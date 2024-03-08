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
        this.nomeApp = new String[10];
        this.mensagens = new String[10];
    }

    public Telemovel (String marca, String modelo, int resolucaoX, int resolucaoY, int armazenamentoFotos, int armazenamentoApps, int armazenamentoTotal, int armazenamentoOcupado, int fotosGuardadas, int appsInstaladas, String [] nomeApp, String [] mensagens){
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

    public Telemovel getMarca(){
        return this.marca;
    }

    public Telemovel getModelo(){
        return this.modelo;
    }

    public Telemovel getResolucaoX(){
        return this.resolucaoX;
    }

    public Telemovel getResolucaoY(){
        return this.resolucaoY;
    }

    public Telemovel getArmazenamentoFotos(){
        return this.armazenamentoFotos;
    }

    public Telemovel getArmazenamentoApps(){
        return this.armazenamentoApps;
    }

    public Telemovel getArmazenamentoTotal(){
        return this.armazenamentoTotal;
    }

    public Telemovel getArmazenamentoOcupado(){
        return this.armazenamentoOcupado;
    }

    public Telemovel getFotosGuardadas(){
        return this.fotosGuardadas;
    }

    public Telemovel getAppsInstaladas(){
        return this.appsInstaladas;
    }

    public Telemovel getNomeApp(){
        return this.nomeApp;
    }

    public Telemovel getMensagens(){
        return this.mensagens;
    }

    public void setMarca(String marca){
        this.marca = marca;
    }

    public void setModelo(String modelo){
        this.modelo = modelo;
    }

    public void setResolucaoX(int resolucaoX){
        this.resolucaoX = resolucaoX;
    }

    public void setResolucaoY(int resolucaoY){
        this.resolucaoY = resolucaoY;
    }

    public void setArmazenamentoFotos(int armazenamentoFotos){
        this.armazenamentoFotos = armazenamentoFotos;
    }

    public void setArmazenamentoApps(int armazenamentoApps){
        this.armazenamentoApps = armazenamentoApps;
    }

    public void setArmazenamentoTotal(int armazenamentoTotal){
        this.armazenamentoTotal = armazenamentoTotal;
    }

    public void setArmazenamentoOcupado(int armazenamentoOcupado){
        this.armazenamentoOcupado = armazenamentoOcupado;
    }

    public void setFotosGuardadas(int fotosGuardadas){
        this.fotosGuardadas = fotosGuardadas;
    }

    public void setAppsInstaladas(int appsInstaladas){
        this.appsInstaladas = appsInstaladas;
    }
    
    public void setNomeApp(String [] nomeApp){
        this.nomeApp = nomeApp;
    }

    public void setMensagens(String [] mensagens){
        this.mensagens = mensagens;
    }

    public boolean existeEspaco(int numeroBytes){
        if(getArmazenamentoTotal() > getArmazenamentoOcupado) return true;
        else return false;
    }

    public void installaApp (String nome, int tamanho){
        if(existeEspaco(tamanho)){
            setArmazenamentoOcupado(getArmazenamentoOcupado() + tamanho);
            setAppsInstaladas(getAppsInstaladas() + 1);
            for(int i = 0; i < getNomeApp().length; i++){
                if(getNomeApp()[i] == null){
                    getNomeApp()[i] = nome;
                    break;
                }
            }
        }
    }

    public void recebeMsg(String msg){
        for(int i = 0; i < getMensagens().length; i++){
            if(getMensagens()[i] == null){
                getMensagens()[i] = msg;
                break;
            }
        }
    }

    public int tamanhoMedioApps(){
        int total = 0;
        for(int i = 0; i < getNomeApp().length; i++){
            if(getNomeApp()[i] != null){
                total += getNomeApp()[i].length();
            }
        }
        return total / getAppsInstaladas();
    }

    public String maiorMsg(){
        String maior = "";
        for(int i = 0; i < getMensagens().length; i++){
            if(getMensagens()[i] != null){
                if(getMensagens()[i].length() > maior.length()){
                    maior = getMensagens()[i];
                }
            }
        }
        return maior;
    }

    public void removeApp(String nome){
        for(int i = 0; i < getNomeApp().length; i++){
            if(getNomeApp()[i].equals(nome)){
                setArmazenamentoOcupado(getArmazenamentoOcupado() - getNomeApp()[i].length());
                getNomeApp()[i] = null;
                break;
            }
        }
    }
}