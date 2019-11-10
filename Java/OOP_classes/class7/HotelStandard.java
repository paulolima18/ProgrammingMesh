

public class HotelStandard extends Hotel implements CartaoPontos{

	//-------------------------------------------------------------

	//Se estiver a true indica epoca alta
	private boolean epocaAlta;
	private int pontos;
	//-------------------------------------------------------------

	public HotelStandard (String codigo,
						  String nome,
						  String local,
						  int cat,
						  int quartos,
						  double preco,
						  boolean epoca) {

		super(codigo, nome, local, cat, quartos, preco);

		this.epocaAlta = epoca;
	}

	public HotelStandard (HotelStandard hs) {

		super(hs);

		this.epocaAlta = hs.getEpoca();

	}

	public HotelStandard () {

		super();

		this.epocaAlta = false;
	}

	//-------------------------------------------------------------

	public HotelStandard clone() {

		return new HotelStandard(this);
	}

	public boolean equals (Object o) {

        if (this == o) return true;

        if ((o == null) || (this.getClass() != o.getClass()))
            return false;

        HotelStandard h = (HotelStandard) o;

        return(super.equals(h) && h.getEpoca() == this.epocaAlta);
	}

	public String toString () {

		StringBuilder s = new StringBuilder();

		s.append("\n:: Hotel Standard:\n");
		s.append(super.toString());
		s.append("Epoca: ").append(this.epocaAlta).append("\n");
		s.append("Preco nesta epoca: ")
		 .append(this.precoPorQuarto())
		 .append(" $\n\n");

		return s.toString();
	}

	//-------------------------------------------------------------

	public double precoPorQuarto() {

		double precoFinal = super.getPrecoQuarto()
							+ (this.epocaAlta==true?20:0);

		return precoFinal;
	}

	public boolean getEpoca() {

		return this.epocaAlta;
	}

	public void setEpoca(boolean epocaAlta) {

		this.epocaAlta = epocaAlta;
	}

	//-------------------------------------------------------------
	public void setPontos(int p)
	{
		this.pontos = p;
	}

	public int getPontos()
	{
		return (int) this.pontos*(int)(this.epocaAlta?1:1.5);
	}
}
