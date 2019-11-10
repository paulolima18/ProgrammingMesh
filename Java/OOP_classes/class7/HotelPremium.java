


public class HotelPremium extends Hotel implements CartaoPontos{

	//-------------------------------------------------------------

	private double taxaLuxo;
	private int pontos;
	//-------------------------------------------------------------

	public HotelPremium (String codigo,
						  String nome,
						  String local,
						  int cat,
						  int quartos,
						  double preco,
						  double taxa) {

		super(codigo, nome, local, cat, quartos, preco);

		this.taxaLuxo = taxa;
	}

	public HotelPremium (HotelPremium hp) {

		super(hp);

		this.taxaLuxo = hp.getTaxaLuxo();

	}

	public HotelPremium () {

		super();

		this.taxaLuxo = 0.0;
	}

	//-------------------------------------------------------------

	public HotelPremium clone() {

		return new HotelPremium(this);
	}

	public boolean equals (Object o) {

        if (this == o) return true;

        if ((o == null) || (this.getClass() != o.getClass()))
            return false;

        HotelPremium h = (HotelPremium) o;

        return(super.equals(h) && h.getTaxaLuxo() == this.taxaLuxo);
	}

	public String toString () {

		StringBuilder s = new StringBuilder();

		s.append("\n:: Hotel Premium:\n");
		s.append(super.toString());
		s.append("Taxa aplicavel: ").append(this.taxaLuxo).append(" %\n");
		s.append("Preco (Com taxa de luxo): ")
		 .append(this.precoPorQuarto())
		 .append(" $\n\n");

		return s.toString();
	}

	//-------------------------------------------------------------

	public double precoPorQuarto() {

		double precoFinal = super.getPrecoQuarto() * this.taxaLuxo;

		return precoFinal;
	}

	//-------------------------------------------------------------

	public double getTaxaLuxo () {

		return this.taxaLuxo;
	}

	public void setTaxaLuxo (double taxa) {

		this.taxaLuxo = taxa;
	}

	//-------------------------------------------------------------
	public void setPontos(int p)
	{
		this.pontos = p;
	}

	public int getPontos()
	{
		return this.pontos;
	}
}
