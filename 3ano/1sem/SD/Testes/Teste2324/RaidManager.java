import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;
import java.util.List;

interface Manager {
    Raid join(String name, int minPlayers) throws InterruptedException;
}

interface Raid {
    List<String> players();
    void waitStart() throws InterruptedException;
    void leave();
}

public class RaidManager implements Manager {
    private final List<String> players = new ArrayList<>(); // Array para colocar os jogadores em espera
    private final List<RaidImp> activeRaids = new ArrayList<>(); // Raids ativas
    private final Lock lock = new ReentrantLock();
    private final Condition raidReady = lock.newCondition();
    private final int R = 10; // Número máximo de raids simultâneos


    /*
     * @raciocinio Este método é responsável por adicionar um jogador a uma raid. Para isso, ele adiciona o jogador
     * na lista de jogadores e verifica se é possível formar uma raid com o número mínimo de jogadores. Caso não seja
     * possível, ele aguarda até que seja possível formar uma raid. Quando é possível formar uma raid, ele cria uma
     * nova raid e adiciona os jogadores a ela. Por fim, ele retorna a raid criada.
     */
    public Raid join(String name, int minPlayers) throws InterruptedException {
        lock.lock();
        try {
            players.add(name); // Adiciona o jogador à lista de jogadores
            while (!canFormRaid(minPlayers)) { // Enquanto não for possível formar uma raid esta é a tal condition
                raidReady.await(); // por isso as threads ficam à espera
            }
            RaidImp raid = new RaidImp(new ArrayList<>(players)); // caso contrario vamos criar a raid com os jogadores
            activeRaids.add(raid); // adicionamos às raids ativas
            players.clear(); // Limpa a lista de jogadores para a próxima raid
            raidReady.signalAll(); // Notifica todas as threads que uma raid foi formada
            return raid;
        } finally {
            lock.unlock();
        }
    }

    private boolean canFormRaid(int minPlayers) {
        return players.size() >= minPlayers && activeRaids.size() < R; // existe um numero minimo de jogadores na raid e um limite de raids ativas
    }

    public class RaidImp implements Raid {
        private final List<String> raidPlayers; // Lista de jogadores da raid
        private boolean started = false; // Flag para indicar se a raid já começou

        RaidImp(List<String> players) {
            this.raidPlayers = players;
        }

        public List<String> players() {
            return raidPlayers;
        }

        public void waitStart() throws InterruptedException {
            lock.lock();
            try {
                while (!started) { // Enquanto a raid não começar
                    raidReady.await();
                }
            } finally {
                lock.unlock();
            }
        }

        public void leave() {
            lock.lock();
            try {
                raidPlayers.remove(Thread.currentThread().getName()); // Remove o jogador da raid
                if (raidPlayers.isEmpty()) {
                    activeRaids.remove(this);
                    raidReady.signalAll();
                }
            } finally {
                lock.unlock();
            }
        }

        void start() {
            lock.lock();
            try {
                started = true;
                raidReady.signalAll();
            } finally {
                lock.unlock();
            }
        }
    }
}

/*
 * @TEACHER SOLUTION
 * 
 * public class RaidManager implements Manager {
 *    private final int R = 10;
 *    private RaidImp current = new RaidImp();
 *    pivate Lock l = new ReentrantLock();
 *    private Condition c = l.newCondition();
 *    private int running = 0;
 * 
 *    public synchronized Raid join(String name, int minPlayers) throws InterruptedException {
 *      l.lock();
 *      try {
 *          RaidImp raid = current;
 *          raid.add(name);
 *          raid.maxMins = Math.max(raid.maxMins, minPlayers);
 *          if (raid.players.size() < raid.maxMins) {
 *              while (current == raid) {
 *                  c.await();
 *              }   
 *          }
 *          else {
 *              current = new RaidImp();
 *              c.signalAll();
 *          }
 *          return raid;
 *      }
 *      finally {
 *         l.unlock();
 *      }
 * 
 * 
 * }
 * 
 * private void finished (){
 *   l.lock();
 *   try {
 *     running--;
 *     c.signalAll();
 *   }
 *      finally {
 *          l.unlock();
 *   }
 *}
 * 
 * public class RaidImp implements Raid {
 *   List<String> players = new ArrayList<>();
 *   Lock l = new ReentrantLock();
 *   Condition c = l.newCondition();
 *   int maxMins = 0;
 *   int left = 0; 
 *          
 *   public List<String> players() {
 *    return players;
 *  }
 * 
 *   public void waitStart() throws InterruptedException {
 * 
 *   public void leave() {
 *      l.lock();
 *      try {
 *         left++;
 *         if (left == players.size()) {
 *            finsihed();
 *      }
 *     finally {
 *       l.unlock();
 *    }
 * }
 */
