package br.ufba.mata55.lista2.exercicio4;

public class Pedido {
	private String data;
	private int codigo;
	private double precoTotal;
	private int status; //1 = solicitado, 2 = enviado, 3 = concluído
	private int quantidade;
	private Item item;
	
	public Pedido(String data, int codigo, double precoTotal, int status,
			int quantidade, Item item) {
		this.data = data;
		this.codigo = codigo;
		this.precoTotal = precoTotal;
		this.status = status;
		this.quantidade = quantidade;
		this.item = item;
	}
	public String getData() {
		return data;
	}
	public void setData(String data) {
		this.data = data;
	}
	public int getCodigo() {
		return codigo;
	}
	public void setCodigo(int codigo) {
		this.codigo = codigo;
	}
	public double getPrecoTotal() {
		return precoTotal;
	}
	public void setPrecoTotal(double precoTotal) {
		this.precoTotal = precoTotal;
	}
	public void setPrecoTotal() {
		precoTotal = quantidade * item.getPreco();
	}
	public int getStatus() {
		return status;
	}
	public void setStatus(int status) {
		this.status = status;
	}
	public int getQuantidade() {
		return quantidade;
	}
	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
		setPrecoTotal();
	}
	public Item getItem() {
		return item;
	}
	public void setItem(Item item) {
		this.item = item;
		setPrecoTotal();
	}
}
