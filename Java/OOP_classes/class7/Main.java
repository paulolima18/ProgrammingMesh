import java.util.Collection;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.List;

import java.*;
// import java.io.ClassNotFoundException;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Main {

	public static void main(String[] args) {

		//Criação de hoteis e grupos de hoteis (HoteisInc)

		HoteisInc grupoIbis = new HoteisInc();
		try {
			grupoIbis = HoteisInc.lerHoteisInc("estado.obj");
		}
		catch (IOException e) {
			System.out.println("meh");
			Hotel ibis1 = new HotelStandard("0001", //codigo
											"ibis1", //nome
											"Lisboa, Portugal", //localidade
											3, //categoria
											74, //nr de quartos
											84.35, //preco por quarto
											false); //Epoca alta? -> false

			Hotel ibis2 = new HotelPremium("0002",
											"ibis2",
											"Braga, Portugal",
											1,
											15,
											32.25,
											0.8); //taxa de luxo * preco

			Hotel ibis3 = new HotelStandard("0003", //codigo
											"ibis3", //nome
											"Madrid, Espanha", //localidade
											4, //categoria
											190, //nr de quartos
											131.25, //preco por quarto
											false); //Epoca alta? -> false

			//Adicionar os hoteis aos seus grupos

			grupoIbis.adicionaHotel(ibis1);
			grupoIbis.adicionaHotel(ibis2);
			grupoIbis.adicionaHotel(ibis3);

			//Get dos hoteis para uma lista de hoteis do sistema

			System.out.println("\nExiste hotel ibis1? "
				+ (grupoIbis.existeHotel("0001")?"Sim":"Não"));

			System.out.println("Quantos hoteis existem? "
				+ (grupoIbis.quantos()));

			System.out.println("Quantos hoteis existem em Braga, Portugal? "
				+ (grupoIbis.quantos("Braga, Portugal")));

			System.out.println("Quantos hoteis Standard existem? "
				+ (grupoIbis.quantosT("HotelStandard")));

			//Colocar os hoteis standard do ibis para epoca alta
			grupoIbis.mudaPara(true);

			Collection<Hotel> hoteisIbis = new ArrayList<>();
			hoteisIbis = grupoIbis.getHoteis();

			System.out.println("\n=> Hoteis IBIS: \n"
				+ hoteisIbis.toString());

			Comparator<Hotel> c = (Hotel h1, Hotel h2) -> {return (int) ((h1.getPrecoQuarto())-h2.getPrecoQuarto());};
			grupoIbis.addCriterioOrd("quartos",new CompNumQuartos());
			grupoIbis.addCriterioOrd("preco",c);

			//System.out.println(grupoIbis.ordenarHoteis());
			System.out.println(grupoIbis.ordenarHoteis(new CompNumQuartos()));
			System.out.println(grupoIbis.ordenarHoteis("quartos"));
			System.out.println(grupoIbis.ordenarHoteis("preco"));
		}


		try {
			grupoIbis.exportaCSV("teste.csv");
		}
		catch (FileNotFoundException e) {
			System.out.println("Erro no acesso ao ficheiro: "+e.getMessage());
		}
		try {
			grupoIbis.guardaEstado("estado.obj");
		}
		catch (IOException e) {
			System.out.println("Erro ao gravar no ficheiro! "+e.getMessage());
		}
	}
}

/*

NOTAS ADICIONAIS:

// this.hoteis = hoteis.entrySet()
//                     .stream()
//                     .collect(toMap(e->e.getKey(), e->e.getValue().clone())

*/
