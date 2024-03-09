
public class Telemovel {
    
    private String marca;
    private String modelo;
    private int resolucaoX;
    private int resolucaoY;
    private int armazenamentoFotos;
    private int armazenamentoApps;
    private int armazenamentoTotal;
    private int armazenamentoOcupado;
    private int fotosGuardadas;
    private int appsInstaladas;
    private String [] nomeApp;
    private String [] mensagens;

    public Telemovel(){
        this.marca = "";
        this.modelo = "";
        this.resolucaoX = 0;
        this.resolucaoY = 0;
        this.armazenamentoFotos = 0;
        this.armazenamentoApps = 0;
        this.armazenamentoTotal = 0;
        this.armazenamentoOcupado = 0;
        this.fotosGuardadas = 0;
        this.appsInstaladas = 0;
        this.nomeApp = new String[100];
        this.mensagens = new String[100];
    }

    public Telemovel(String marca, String modelo, int resolucaoX, int resolucaoY, int armazenamentoFotos, int armazenamentoApps, int armazenamentoTotal, int armazenamentoOcupado, int fotosGuardadas, int appsInstaladas, String[] nomeApp, String[] mensagens){
        this.marca = marca;
        this.modelo = modelo;
        this.resolucaoX = resolucaoX;
        this.resolucaoY = resolucaoY;
        this.armazenamentoFotos = armazenamentoFotos;
        this.armazenamentoApps = armazenamentoApps;
        this.armazenamentoTotal = armazenamentoTotal;
        this.armazenamentoOcupado = armazenamentoOcupado;
        this.fotosGuardadas = fotosGuardadas;
        this.appsInstaladas = appsInstaladas;
        this.nomeApp = nomeApp;
        this.mensagens = mensagens;
    }

    public Telemovel(Telemovel umTelemovel){
        this.marca = umTelemovel.getMarca();
        this.modelo = umTelemovel.getModelo();
        this.resolucaoX = umTelemovel.getResolucaoX();
        this.resolucaoY = umTelemovel.getResolucaoY();
        this.armazenamentoFotos = umTelemovel.getArmazenamentoFotos();
        this.armazenamentoApps = umTelemovel.getArmazenamentoApps();
        this.armazenamentoTotal = umTelemovel.getArmazenamentoTotal();
        this.armazenamentoOcupado = umTelemovel.getArmazenamentoOcupado();
        this.fotosGuardadas = umTelemovel.getFotosGuardadas();
        this.appsInstaladas = umTelemovel.getAppsInstaladas();
        this.nomeApp = umTelemovel.getNomeApp();
        this.mensagens = umTelemovel.getMensagens();
    }

    public String getMarca(){
        return this.marca;
    }

    public String getModelo(){
        return this.modelo;
    }

    public int getResolucaoX(){
        return this.resolucaoX;
    }

    public int getResolucaoY(){
        return this.resolucaoY;
    }

    public int getArmazenamentoFotos(){
        return this.armazenamentoFotos;
    }

    public int getArmazenamentoApps(){
        return this.armazenamentoApps;
    }

    public int getArmazenamentoTotal(){
        return this.armazenamentoTotal;
    }

    public int getArmazenamentoOcupado(){
        return this.armazenamentoOcupado;
    }

    public int getFotosGuardadas(){
        return this.fotosGuardadas;
    }

    public int getAppsInstaladas(){
        return this.appsInstaladas;
    }

    public String[] getNomeApp(){
        return this.nomeApp;
    }

    public String[] getMensagens(){
        return this.mensagens;
    }

    public boolean existeEspaco(int numeroBytes){
        if(this.armazenamentoTotal - this.armazenamentoOcupado >= numeroBytes) return true;
        else return false;
    }

    // public void installaApp(String nome, int tamanho){
    //     if(existeEspaco(tamanho)){
    //         setArmazenamentoOcupado(this.armazenamentoOcupado + tamanho);
    //         this.appsInstaladas++;
    //         for(int i = 0; i < this.nomeApp.length; i++){
    //             if(this.nomeApp[i] == null){
    //                 this.nomeApp[i] = nome;
    //                 break;
    //             }
    //         }
    //     }
    // }

    public int tamanhoMedioApps(){
        if(this.appsInstaladas == 0) return 0;
        int total = 0;
        for(String appNome : this.nomeApp){
            if(appNome != null){
                total += appNome.length(); // Suposição: substituindo pelo comprimento do nome como aproximação do tamanho
            }
        }
        return total / this.appsInstaladas;
    }

    public void removeApp(String nome){
        for(int i = 0; i < this.nomeApp.length; i++){
            if(nome.equals(this.nomeApp[i])){
                this.armazenamentoOcupado -= nome.length();
                this.nomeApp[i] = null;
                this.appsInstaladas--;
                break;
            }
        }
    }
}
