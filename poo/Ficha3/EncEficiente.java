
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Date; // Import the Data class

public class EncEficiente{
    private String nome;
    private int nif;
    private String [] morada;
    private int nEnc;
    private Date data; // Change the type to Date
    private ArrayList<LinhaEncomenda> linhas;

    /**
     * @brief Constructor for the EncEficiente class
     */
    public EncEficiente(){
        this.nome = "";
        this.nif = 0;
        this.morada = new String[2];
        this.nEnc = 0;
        this.data = new Date(); // Initialize the date
        this.linhas = new ArrayList<LinhaEncomenda>();
    }

    /**
     * @brief Constructor for the EncEficiente class
     * @param nome
     * @param nif
     * @param morada
     * @param nEnc
     * @param data
     * @param linhas
     */
    public EncEficiente(String nome, int nif, String [] morada, int nEnc, Date data, ArrayList<LinhaEncomenda> linhas){
        this.nome = nome;
        this.nif = nif;
        this.morada = morada;
        this.nEnc = nEnc;
        this.data = data;
        this.linhas = new ArrayList<LinhaEncomenda>();
        for(LinhaEncomenda l : linhas){
            this.linhas.add(l.clone());
        }
    }

    /**
     * @brief Constructor for the EncEficiente class
     * @param e
     */
    public EncEficiente(EncEficiente e){
        this.nome = e.getNome();
        this.nif = e.getNif();
        this.morada = e.getMorada();
        this.nEnc = e.getNEnc();
        this.data = e.getData();
        this.linhas = e.getLinhas();
    }
    
    /**
     * @brief Get the name
     * @return
     */
    public String getNome(){
        return this.nome;
    }

    /**
     * @brief Get the NIF
     * @return
     */
    public int getNif(){
        return this.nif;
    }

    /**
     * @brief Get the address
     * @return
     */
    public String [] getMorada(){
        return this.morada;
    }

    /**
     * @brief Get the number of the order
     * @return
     */
    public int getNEnc(){
        return this.nEnc;
    }

    /**
     * @brief Get the date
     * @return
     */
    public Date getData(){
        return this.data;
    }

    /**
     * @brief Get the lines
     * @return
     */
    public ArrayList<LinhaEncomenda> getLinhas(){
        ArrayList<LinhaEncomenda> res = new ArrayList<LinhaEncomenda>();
        for(LinhaEncomenda l : this.linhas){
            res.add(l.clone());
        }
        return res;
    }

    /**
     * @brief Set the name
     * @param nome
     */
    public void setNome(String nome){
        this.nome = nome;
    }
    
    /**
     * @brief Clone the LinhaEncomenda object
     * @return a clone of the LinhaEncomenda object
     */
    public LinhaEncomenda clone(){
        return new LinhaEncomenda(this);
    }

    /**
     * @brief Set the NIF
     * @param nif
     */
    public void setNif(int nif){
        this.nif = nif;
    }

    /**
     * @brief Set the address
     * @param morada
     */
    public void setMorada(String [] morada){
        this.morada = morada;
    }  

    /**
     * @brief Set the number of the order
     * @param nEnc
     */
    public void setNEnc(int nEnc){
        this.nEnc = nEnc;
    }

    /**
     * @brief Set the date
     * @param data
     */
    public void setData(Date data){
        this.data = data;
    }

    /**
     * @brief Set the lines
     * @param linhas
     */
    public void setLinhas(ArrayList<LinhaEncomenda> linhas){
        this.linhas = new ArrayList<LinhaEncomenda>();
        for(LinhaEncomenda l : linhas){
            this.linhas.add(l.clone());
        }
    }

    /**
     * @brief Add a line to the order
     * @param linha
     */
    public EncEficiente clone() {
        EncEficiente newEnc = new EncEficiente();
        newEnc.setNome(this.nome);
        newEnc.setNif(this.nif);
        newEnc.setMorada(this.morada.clone()); // Make a copy of the array
        newEnc.setNEnc(this.nEnc);
        newEnc.setData((Date)this.data.clone()); // Ensure Date is cloned properly
        for (LinhaEncomenda l : this.linhas) {
            newEnc.getLinhas().add(l.clone());
        }
        return newEnc;
    }
    /**
     * @brief Add a line to the order
     * @param linha
     */
    public boolean equals(Object o) {
        if (this == o) return true;
        if ((o == null) || (getClass() != o.getClass())) return false;
        EncEficiente that = (EncEficiente) o;
        return nif == that.nif &&
                nEnc == that.nEnc &&
                nome.equals(that.nome) &&
                Arrays.equals(morada, that.morada) && // Correct way to compare arrays
                data.equals(that.data) &&
                linhas.equals(that.linhas);
    }

    /**
     * @brief Calculates the total value of the order
     * @param linha
     */
    public double calculaValorTotal(){
        double total = 0;
        for(LinhaEncomenda l : this.linhas){
            total += l.calculaValorLinhaEnc();
        }
        return total;
    }
}