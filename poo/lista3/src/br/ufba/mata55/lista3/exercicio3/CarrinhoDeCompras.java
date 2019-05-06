package br.ufba.mata55.lista3.exercicio3;

import java.util.ArrayList;

public class CarrinhoDeCompras {
	private int precoTotal;
	private ArrayList<Filme> filmes; 
	
	public CarrinhoDeCompras() {
		this.precoTotal = 0;
		this.filmes = new ArrayList<Filme>();
	}
	
	public int getPrecoTotal() {
		return precoTotal;
	}
	public void setPrecoTotal(int precoTotal) {
		this.precoTotal = precoTotal;
	}
	public ArrayList<Filme> getFilmes() {
		return filmes;
	}
	public void setFilmes(ArrayList<Filme> filmes) {
		this.filmes = filmes;
	}
	
	public void insereFilme(Filme filme){
		filmes.add(filme);
		setPrecoTotal(getPrecoTotal()+filme.getPreco());
	}
	public void imprimeRecibo(){
		for (Filme filme : filmes){
			  System.out.println(filme.toString());
		}
	}
	public static void main(String[] args) {
		CarrinhoDeCompras carrinho = new CarrinhoDeCompras();
		carrinho.insereFilme(new Filme("Titanic"));
		carrinho.insereFilme(new FilmeInfantil("Big Hero 6"));
		carrinho.insereFilme(new FilmeLancamento("Capita Marvel"));
		carrinho.imprimeRecibo();
		System.out.println(carrinho.getPrecoTotal());
	}
}
