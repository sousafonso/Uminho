import java.util.ArrayList;

public class Telemovel {
    private String marca;
    private String modelo;
    private ArrayList<String> appsInstaladas;
    private int nfotos;
    private int napps;
    private int espaco;
    private int displayX;
    private int displayY;
    private ArrayList<String> mensagens;
    private int armazenamentoMsgs;
    private int armazenamentoTotal;
    private int armazenamentoFotos;
    private int armazenamentoApps;

    public boolean existeEspaco(int numeroBytes) {
        return (armazenamentoTotal - espacoOcupado) >= numeroBytes;
    }

    public void instalaApp(String nome, int tamanho) {
        if (existeEspaco(tamanho)) {
            appsInstaladas.add(nome);
            espacoOcupado += tamanho;
            numeroApps++;
            armazenamentoApps += tamanho;
        } else {
            System.out.println("Não há espaço suficiente para instalar a aplicação " + nome);
        }
    }

    public void recebeMsg(String msg){
        if (mensagens.size() < armazenamentoMsgs) {
            mensagens.add(msg);
            espacoOcupado += msg.getBytes().length;
        } else {
            System.out.println("Não há espaço suficiente para armazenar a mensagem.");
        }
    }

    public double tamMedioApps(){
        public double tamMedioApps() {
            return numeroApps == 0 ? 0 : (double) armazenamentoApps / numeroApps;
        }
    }

    public String maiorMsg() {
        if (mensagens.isEmpty()) return null;
        String maior = mensagens.get(0);
        for (String msg : mensagens) {
            if (msg.length() > maior.length()) {
                maior = msg;
            }
        }
        return maior;
    }

    public void removeApp(String nome, int tamanho){
        numeroApps--;
        espacoOcupado -= tamanho;
        appsInstaladas.remove(nome);
        armazenamentoApps-= tamanho;
    }

    public String getMarca() { return marca; }
    public void setMarca(String marca) { this.marca = marca; }

    public String getModelo() { return modelo; }
    public void setModelo(String modelo) { this.modelo = modelo; }

    public int getResolucaoX() { return resolucaoX; }
    public void setResolucaoX(int resolucaoX) { this.resolucaoX = resolucaoX; }

    public int getResolucaoY() { return resolucaoY; }
    public void setResolucaoY(int resolucaoY) { this.resolucaoY = resolucaoY; }

    public int getArmazenamentoMsgs() { return armazenamentoMsgs; }
    public void setArmazenamentoMsgs(int armazenamentoMsgs) { this.armazenamentoMsgs = armazenamentoMsgs; }

    public int getArmazenamentoTotal() { return armazenamentoTotal; }
    public void setArmazenamentoTotal(int armazenamentoTotal) { this.armazenamentoTotal = armazenamentoTotal; }

    public int getArmazenamentoFotos() { return armazenamentoFotos; }
    public void setArmazenamentoFotos(int armazenamentoFotos) { this.armazenamentoFotos = armazenamentoFotos; }

    public int getArmazenamentoApps() { return armazenamentoApps; }
    public void setArmazenamentoApps(int armazenamentoApps) { this.armazenamentoApps = armazenamentoApps; }

    public int getEspacoOcupado() { return espacoOcupado; }
    public void setEspacoOcupado(int espacoOcupado) { this.espacoOcupado = espacoOcupado; }

    public int getNumeroFotos() { return numeroFotos; }
    public void setNumeroFotos(int numeroFotos) { this.numeroFotos = numeroFotos; }

    public int getNumeroApps() { return numeroApps; }
    public void setNumeroApps(int numeroApps) { this.numeroApps = numeroApps; }

    public ArrayList<String> getAppsInstaladas() { return appsInstaladas; }
    public void setAppsInstaladas(ArrayList<String> appsInstaladas) { this.appsInstaladas = appsInstaladas; }

    public ArrayList<String> getMensagens() { return mensagens; }
    public void setMensagens(ArrayList<String> mensagens) { this.mensagens = mensagens; }

    public Telemovel(String marca, String modelo, int resolucaoX, int resolucaoY, int armazenamentoMsgs, int armazenamentoTotal) {
        this.marca = marca;
        this.modelo = modelo;
        this.resolucaoX = resolucaoX;
        this.resolucaoY = resolucaoY;
        this.armazenamentoMsgs = armazenamentoMsgs;
        this.armazenamentoTotal = armazenamentoTotal;
        this.armazenamentoFotos = 0;
        this.armazenamentoApps = 0;
        this.espacoOcupado = 0;
        this.numeroFotos = 0;
        this.numeroApps = 0;
        this.appsInstaladas = new ArrayList<>();
        this.mensagens = new ArrayList<>();
    }

    // public Telemovel(){
    //     this.marca = "N/A";
    //     this.modelo = "N/A";
    //     this.nfotos = 0;
    //     this.napps = 0;
    //     this.espaco = 0;
    //     this.displayX = 0;
    //     this.displayY = 0;
    // }

    // public Telemovel(Telemovel t){
    //     this.marca = t.getMarca();
    //     this.modelo = t.getModelo();
    //     this.nfotos = t.getNFotos();
    //     this.napps = t.getNApps();
    //     this.espaco = t.getEspaco();
    //     this.displayX = t.getDisplayX();
    //     this.displayY = t.getDisplayY();
    // }

    public static void main(String[] args) {
        Telemovel meuTelemovel = new Telemovel("MarcaX", "ModeloY", 1080, 1920, 100, 10000);

        // Testando a instalação de aplicações
        meuTelemovel.instalaApp("App1", 200);
        meuTelemovel.instalaApp("App2", 300);
        meuTelemovel.instalaApp("App3", 100);

        // Testando a recepção de mensagens
        meuTelemovel.recebeMsg("Olá, tudo bem?");
        meuTelemovel.recebeMsg("Mensagem muito maior que a anterior.");

        // Imprimindo o tamanho médio das aplicações
        System.out.println("Tamanho médio das aplicações: " + meuTelemovel.tamMedioApps());

        // Imprimindo a maior mensagem recebida
        System.out.println("Maior mensagem recebida: " + meuTelemovel.maiorMsg());

        // Testando a desinstalação de aplicações
        meuTelemovel.removeApp("App2", 300);
        System.out.println("Número de aplicações instaladas após desinstalação: " + meuTelemovel.getNumeroApps());
    }
}