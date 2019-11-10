import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.TreeSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Collection;

import java.lang.Class;

// import java.util.ClassNotFoundException;
import java.io.FileNotFoundException;
import java.io.ObjectOutputStream;
import java.io.ObjectInputStream;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.Serializable;
import java.io.IOException;
import java.io.PrintWriter;

public class HoteisInc implements Serializable{

	//----------------------------------------------------------------//

	private Map<String, Hotel> cadeiaHoteis;
	private static Map<String, Comparator<Hotel>> criteriosOrd = new HashMap<>();
	//----------------------------------------------------------------//

	public static void addCriterioOrd(String nome,Comparator<Hotel> c) {
		HoteisInc.criteriosOrd.put(nome,c);
	}

	public HoteisInc (Map<String, Hotel> novaCadeia) {

		//this.cadeiaHoteis = new HashMap<String, Hotel> (novaCadeia);
		this.cadeiaHoteis = novaCadeia.entrySet()
			   	                      .stream()
				                      .collect(Collectors.toMap(e->e.getKey(),
				                      	       e->e.getValue().clone()));
		//Para hashmap
				    // .collect(Collectors.toMap(e->e.getKey(),
				    //                	          e->e.getValue().clone()),
				    // 						  	  (e1, e2) -> e2,
				    // 						  	  HashMap::new);

	}

	public HoteisInc (HoteisInc grupoHoteis) {

		this.cadeiaHoteis = new HashMap<String, Hotel>(grupoHoteis.getCadeiaHoteis());
	}

	public HoteisInc () {

		this.cadeiaHoteis = new HashMap<String, Hotel>();
	}

	//----------------------------------------------------------------//

	public HoteisInc clone () {

		return new HoteisInc(this);
	}

	public String toString () {

		return this.cadeiaHoteis.toString();
	}

	public boolean equals (Object o) {

        if (this == o) return true;

        if ((o == null) || (this.getClass() != o.getClass()))
            return false;

        HoteisInc h = (HoteisInc) o;

        return(h.equals(this.cadeiaHoteis));
	}

	//----------------------------------------------------------------//

	public void adicionaHotel (Hotel novo) {

		this.cadeiaHoteis.put(novo.getCodigoIdentificacao(),
							  novo.clone());
	}

	public boolean existeHotel (String cod) {

		return this.cadeiaHoteis.containsKey(cod);
	}

	public long quantos () {

		return this.cadeiaHoteis.size();
	}

	public long quantos (String loc) {

		List<Hotel> hoteis = new ArrayList<Hotel>();

		hoteis = this.cadeiaHoteis.values()
		                          .stream()
		                          .collect(Collectors.toList());

		// int quantidade = 0;
		// for (Hotel h: hoteis) {
		// 	if (h.getLocalidade().equals(loc))
		// 		quantidade++;
		// }

		return hoteis.stream()
		             .filter(h -> h.getLocalidade().equals(loc))
		             .count();
	}

	public long quantosT (String tipo) {

		return this.cadeiaHoteis.values()
								.stream()
								.filter(h -> h.getClass().getSimpleName().equals(tipo))
								.count();

	}

	public void mudaPara (boolean epoca) {

		Collection<Hotel> list = new ArrayList<>();

		list = this.cadeiaHoteis.values();

		for (Hotel h: list) {

			if (h.getClass().getSimpleName().equals("HotelStandard")) {
				((HotelStandard) h).setEpoca(epoca);
			}
		}
	}

	//----------------------------------------------------------------//

	public Hotel getHotel (String cod) {
		Hotel h = hoteisIbis.get(cod);

		if (h == null) throw new HotelException("Código "+cod+" inexistente!");

		return h.clone();
	}

	//----------------------------------------------------------------//

	public HashMap<String, Hotel> getCadeiaHoteis () {

		return new HashMap<String, Hotel>(this.cadeiaHoteis);
	}

	public Collection<Hotel> getHoteis() {

		//Esta collection é uma lista de hoteis
		Collection<Hotel> listaHoteis = new ArrayList<>();

		listaHoteis = this.cadeiaHoteis.values()
									   .stream()
									   .map(h -> h.clone())
									   .collect(Collectors.toList());

		return listaHoteis;
	}

	//----------------------------------------------------------------//
	public TreeSet<Hotel> ordenarHoteis() {
		TreeSet<Hotel> res = new TreeSet<>();

		this.cadeiaHoteis.values().forEach(h -> res.add(h.clone()));
		return res;
	}

	public TreeSet<Hotel> ordenarHoteis(Comparator<Hotel> c) {
		return this.cadeiaHoteis.values()
											.stream()
											.map(Hotel::clone)
											.sorted(c)
											.collect(Collectors.toCollection(() -> new TreeSet<Hotel>(c)));
	}

	public TreeSet<Hotel> ordenarHoteis(String criterio) {
		return this.ordenarHoteis(HoteisInc.criteriosOrd.get(criterio));
	}

	public List<CartaoPontos> daoPontos() {

		return this.cadeiaHoteis.values().stream()
																		 .filter(h -> h instanceof CartaoPontos)
																		 .map(Hotel::clone)
																		 .map(h -> (CartaoPontos)h)
																		 .collect(Collectors.toList());
	}

	public void exportaCSV(String fich) throws FileNotFoundException
	{
		PrintWriter pw = new PrintWriter(fich);

		for (Hotel h : this.cadeiaHoteis.values())
		{
			pw.println(h.toString());
		}

		pw.close();

		/*
		try
		{
			PrintWriter pw = new PrintWriter(fich);

			for (Hotel h : this.cadeiaHoteis.values())
			{
				pw.println(h.toString());
			}
			pw.close();
		}
		catch (FileNotFoundException) {

		}
		*/
	}

	public void guardaEstado (String fich) throws IOException
	{
		ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fich));
		oos.writeObject(this);
		oos.close();
	}

	private static HoteisInc lerHoteisInc(String fich) throws IOException
	{
		ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fich));
		HoteisInc hi = (HoteisInc) ois.readObject(this);
		return hi;
	}

	private static List<String> lerCSV()
	{

	}
}
