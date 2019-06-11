Alunos:

Alcides Augusto Bezerra Neto 

Gabriel de Jesus Silva do Lago

Rodada 2
A partir do código que você entregou na rodada 1, realize as alterações indicadas:

Agora a célula do jogador possui poderes especiais. 
	O jogador escolhe o poder ativo teclando 1, 2 ou 3, e 
	usa o poder ativo usando a barra de espaço.
	Todos os poderes fazem alguma coisa com o jogador e/ou com as entidades vizinhas (em um raio de 50 pixels).
	O poder 1 faz com que todas as entidades vizinhas sejam capturadas pela célula, 
		resultando na variação do tamanho da célula. 
		Exemplo: se houver 3 comidas e 2 venenos na vizinhança, 
			o tamanho da célula vai variar da mesma forma que variaria caso a célula tivesse encostado nessas 5 entidades.
	O poder 2 faz com que todas as entidades vizinhas aumentem de tamanho e a célula diminua de tamanho em 3 unidades.
	O poder 3 faz com que todos os venenos vizinhos sejam destruídos e a célula diminua de tamanho em 3 unidades.

Crie uma interface Poder, com o método public void acionar(Celula celula, Collection<Entidade> vizinhos). 
	O método recebe uma referência para a célula e para todas as entidades vizinhas, e 
	modifica os parâmetros de acordo com o poder específico.

Crie as classes Poder1, Poder2 e Poder3, implementando a interface Poder.

A classe Celula deve instanciar os três poderes e guardar em um vetor (Poder[]). 
	Além disso, deve possuir um atributo poderAtivo, 
		que é uma referência para o poder ativo (inicialmente, o poder ativo é o poder 1).

A classe Celula deve possuir um método setPoderAtivo(int numPoder), onde 
	numPoder deve ser 1, 2 ou 3. 
	Se for outro número, deve lançar uma exceção do tipo IllegalArgumentException.
Use o seguinte código em Painel:
	@Override
	public void keyTyped(KeyEvent e) {
		char keyChar = e.getKeyChar();

		if (keyChar == 27) {
			System.exit(0);
		} else if (keyChar >= '1' && keyChar <= '3') {
			terreno.getCelula().setPoderAtivo(keyChar - '0');
		}
	}

Ao capturar um veneno ou comida ou inimigo, a variação de tamanho da célula deve 
	corresponder ao tamanho da entidade capturada.

