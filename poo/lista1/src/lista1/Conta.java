package lista1;

public class Conta {
	String codigo;
	double saldo;
	
	public Conta(String codigo) {
		this.codigo = codigo; 
		this.saldo = 0; 
	}
	
	public Conta(String codigo, double saldo) {
		this.codigo = codigo; 
		this.saldo = saldo; 
	}
	
	boolean retira(double quantia) {
		boolean retirou = false;
		if(quantia <= this.saldo) {
			System.out.println("Saque realizado");
			this.saldo -= quantia;
			retirou = true;
		}
		else
			System.out.println("Saldo insuficiente");
		return retirou;
	}

	void deposita(double quantia) {
		this.saldo += quantia;
		System.out.println("Deposito realizado");
	}
	
	boolean transfere(double quantia, Conta beneficiario) {
		boolean transferiu = false;
		if(quantia <= this.saldo && beneficiario != null) {
			System.out.println("Tranferindo");
			this.saldo -= quantia;
			beneficiario.saldo += quantia;
			transferiu = true;
		}
		else
			System.out.println("Sem saldo para transferir");
		return transferiu;
	}
	
//	public static void main(String[] args) {
//		Conta pt = new Conta("666", 4000);
//		Conta pmdb = new Conta("666+", 50);
//		dumpAll(pt, pmdb);
//		pt.retira(500);
//		pmdb.deposita(500);
//		dumpAll(pt, pmdb);
//		pt.transfere(4001, pmdb);
//		dumpAll(pt, pmdb);
//		pmdb.retira(550);
//		dumpAll(pt, pmdb);
//	}
//
//	public static void dumpAll(Conta pt, Conta pmdb) {
//		dump(pt);
//		dump(pmdb);
//	}
//
//	public static void dump(Conta tal) {
//		System.out.println("Codigo " + tal.codigo);
//		System.out.println("Saldo " + tal.saldo);
//		
//	}
}
