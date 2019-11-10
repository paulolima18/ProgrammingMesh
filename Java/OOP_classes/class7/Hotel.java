import java.io.Serializable;


public abstract class Hotel implements Serializable{

	//----------------------------------------------------------------//

	private String codigoIdentificao;
	private String nome;
	private String localidade;
	private int categoria;
	private int nr_quartos;
	private double precoPorQuarto;

	//----------------------------------------------------------------//

	public Hotel (String codigo,
				  String name,
				  String local,
				  int category,
				  int quartos,
				  double preco) {

		this.codigoIdentificao = codigo;
		this.nome 			   = name;
		this.localidade 	   = local;
		this.categoria 		   = category;
		this.nr_quartos 	   = quartos;
		this.precoPorQuarto    = preco;
	}

	public Hotel (Hotel novo) {

		this.codigoIdentificao = novo.getCodigoIdentificacao();
		this.nome              = novo.getNome();
		this.localidade        = novo.getLocalidade();
		this.categoria         = novo.getCategoria();
		this.nr_quartos        = novo.getNumQuartos();
		this.precoPorQuarto    = novo.getPrecoQuarto();
	}

	public Hotel () {

		this.codigoIdentificao = "0000";
		this.nome              = "Empty name";
		this.localidade        = "In my computer";
		this.categoria         = 0;
		this.nr_quartos        = 0;
		this.precoPorQuarto    = 0;
	}

	//----------------------------------------------------------------//

	public abstract double precoPorQuarto();

	//----------------------------------------------------------------//

	public abstract Hotel clone ();

	public String toString () {

		StringBuilder s = new StringBuilder();

		s.append("\nCodigo: " + this.codigoIdentificao);
		s.append("\nNome: " + this.nome);
		s.append("\nLocalidade: " + this.localidade);
		s.append("\nNº Quartos: " + this.nr_quartos);
		s.append("\nPreco/Quarto: " + this.precoPorQuarto + " $\n");

		return s.toString();
	}

	public boolean equals (Object o) {

        if (this == o) return true;

        if ((o == null) || (this.getClass() != o.getClass()))
            return false;

        Hotel h = (Hotel) o;

        return(h.getCodigoIdentificacao().equals(this.codigoIdentificao) &&
        	   h.getNome().equals(this.nome) &&
        	   h.getLocalidade().equals(this.localidade) &&
        	   h.getNumQuartos() == this.nr_quartos &&
        	   h.getPrecoQuarto() ==this.precoPorQuarto);
	}


	//----------------------------------------------------------------//

	public String getCodigoIdentificacao () {

		return this.codigoIdentificao;
	}

	public String getNome () {

		return this.nome;
	}

	public String getLocalidade () {

		return this.localidade;
	}

	public int getCategoria () {

		return this.categoria;
	}

	public int getNumQuartos () {

		return this.nr_quartos;
	}

	public double getPrecoQuarto () {

		return this.precoPorQuarto;
	}

	public int hashCode () {

		return this.codigoIdentificao.hashCode();
	}

	public int compareTo(Hotel h) {
		return this.nome.compareTo(h.getNome());
	}

	//----------------------------------------------------------------//

}
