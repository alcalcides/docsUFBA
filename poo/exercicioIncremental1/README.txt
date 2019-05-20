Aluno: Alcides Augusto Bezerra Neto

Exercício incremental
O exercício pode ser feito individualmente ou em dupla. 
O exercício consiste de 2 ou 3 rodadas de implementação.

Rodada 1
Crie um jogo 2D no qual o jogador controla uma célula que deve comer comida e evitar 
venenos e inimigos, de acordo com a especificação a seguir.

●	O terreno é preto, visto de cima, e tem tamanho 500x500
●	O terreno contém a célula, comidas e venenos
●	Célula, comidas e venenos possuem coordenadas x e y, tamanho, cor e uma variável 
booleana para indicar se estão ativos
●	A célula é um círculo branco com diâmetro = tamanho; comidas são quadrados verdes 
centrados em (x, y), com lado = tamanho; venenos são quadrados verdes centrados em (x, y), 
com lado = tamanho, e com um círculo azul dentro, de diâmetro = tamanho.
●	Comidas e venenos possuem, adicionalmente, um atributo "ativo", inicialmente verdadeiro
●	A célula é controlada através do mouse
●	Ao encostar em uma comida, ela é desativada e a célula cresce de tamanho
●	Ao encostar em um veneno, ele é desativado e a célula diminui de tamanho
●	Ao ser desativado, a comida ou o veneno deve ser destruído
●	Considere que um objeto encosta no outro se a distância entre eles é menor que a metade 
da soma de seus tamanhos
●	Quando a célula fica com tamanho menor que 3, ela deve ser desativada e destruída.
●	De tempos em tempos novos venenos e comidas são adicionados ao terreno, em posições 
aleatórias e com tamanhos aleatórios (sendo 3 o tamanho mínimo)