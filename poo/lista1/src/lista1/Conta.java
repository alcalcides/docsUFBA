package lista1;

public class Conta {
	String codigo;
	double saldo;
	
	public Conta(String codigo) {
		this.codigo = codigo; 
		this.saldo = 0.0f; 
	}
	
	public Conta(String codigo, double saldo) {
		this.codigo = codigo; 
		this.saldo = saldo; 
	}
	
	boolean retira(double quantia) {
		boolean retirou = false;
		if(quantia <= this.saldo) {
			this.saldo -= quantia;
			retirou = true;
		}
		return retirou;
	}

	void deposita(double quantia) {
		this.saldo += quantia;
	}
	
	boolean transfere(double quantia, Conta beneficiario) {
		boolean transferiu = false;
		if(quantia >= this.saldo && beneficiario != null) {
			transferiu = true;
			this.saldo -= quantia;
			beneficiario.saldo += quantia;
		}
		return transferiu;
	}
	
}
