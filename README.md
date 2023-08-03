# **Trabalho de Aquecimento: Top K Elementos**

Atividade para a disciplina de Algoritmos e Estruturas de Dados II. <br/>

## Sumário

- [Objetivos](#Objetivos)
- [Diretrizes](#Diretrizes)
- [Introdução](#Estrutura)
- [Descisões de Implementação](#Decisões de Implementação)
- [Resultados](#Resultados)
- [Tempo e Custo Computacional](#Tempo e Custo Computacional)
- [Conclusão](#Conclusão)


## Objetivo

O objetivo é desenvolver um algoritmo utilizando-se hash e heap para resolver um problema clássico chamado top k itens. 
O qual é preciso encontrar os k itens mais valiosos de uma coleção de dados. Logo, utiliza-se o hash para contar a frequência de todos os itens, enquanto
o heap se aplica na manutenção de uma lista dos k itens de maior valor. 


## Estrutura

- heap.hpp: Menciona todas as funções utilizadas para o heap e seus parâmetros.
- TopK.cpp: Contém a criação e o desenvolvimento das funções para a tabela hash, são elas:    
- topK.hpp: Menciona todas as funções utilizadas para a hash e seus parâmetros.
- TopK.cpp: Contém a criação e o desenvolvimento das funções para  heap, são elas: 
- main.cpp: Pertence a parte de 
- files.hpp: Inclui biliotecas e arquivos a serem utilizados no programa.
- input.data -> O arquivo de texto para ser lido.

## Diretrizes

As especificações a seguir foram propostas para discussão do problema:

• Criar uma tabela de dispersão (hash) para contar a frequência de cada elemento tok-
enizado da coleção de dados de entrada.
• Crie uma árvore de prioridades (heap) de tamanho k e insira os primeiros k elementos do
hash nela.
1. Para cada elemento restante na hash, compare a contagem com o menor valor do
heap.
2. Se a contagem for maior do que o menor valor da heap, remova o menor valor, insira
o novo elemento e refaça a estrutura.
3. Caso contrário, ignore o elemento e vá para o próximo.
• No final, a heap conterá os k elementos com maiores valores (frequências) da coleção
de dados. Então, imprima-os em ordem crescente.

Este programa deverá ler uma coleção de arquivos contento textos sem nenhuma for-
matação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".",
"?", "!"").
• Cada parágrafo é separado por, pelo menos, uma linha em branco.
• Considere como palavra uma sequência de letras delimitada por espaço em branco, ”col-
una da esquerda”, ”coluna da direita” e símbolos de pontuação.
• Faz parte do projeto do seu programa fornecer uma saída legível.
• Os arquivos a serem utilizados para teste serão disponibilizados junto a essa descrição e
devem ser utilizados para quaisquer validações, não sendo necessário a adoção de mais
entradas para esse processo.
• A documentação detalhando todo o processo de desenvolvimento deve ser produzida
como README.mb e disponibilizada no git junto com o projeto.


## Decisões de implementação


- ```Função tamanho``` : Tem o objetivo de fazer a leitura da primeira linha e descobrir qual a dimensão das matrizes. Esse tamanho inicialmente descoberto será usado para fazer a alocação dinâmica de cada uma.
- ```Função transformar```: A matriz é lida linha por linha e salva como uma matriz de string e em seguida convertida para uma matriz de inteiros, para ser possível realizar a soma do percurso.

- ```Função caminhar```: É a responsável pelo caminho do algoritmo. <br/>
O percurso de cada matriz se inicia na posição [0,0] e é finalizado na posição [tamanho][tamanho]. <br/>
Não é permitido passar pelo mesmo local mais de uma vez e não pode subir para as linhas anteriores.<br/>
Em cada iteração o algoritmo verifica primeiro se é possível acessar uma determinada posição, para que ele não visite lugares vazios.  
Caso seja possível, ele olha qual posição possui o número maior.

  A ordem de verificação é:
  1. Para direita (n° 6)
  2. Para diagonal direita (n° 9)
  3. Para diagonal esquerda (n° 7)
  4. Para esquerda (n° 4)
  5. Para baixo (n° 8)

Modelo ilustrativo para a ordem de verificação:        

<img src="imagens/direcoes.png" height="200" width="200">

<br/>

  De acordo com a posição que o algoritmo estiver, nem sempre será uma possibilidade as 5 direções. <br/>
  Exemplo: Se o algoritmo estiver na posição [1][2], ocupada pelo algarismo 6, ele não tem a opção de ir para direita ou para diagonal direita, pois são posições nulas que não pertencem a matriz. Logo, ele só pode ir para uma das outras três posições disponíveis, consequentemente a que tiver o maior número.

  <img src="imagens/exemplo.png" height="200" width="200">

  <br/>
  O trajeto realizado por cada matriz é alterado pelo valor (-1), para registrar o percurso. <br/>
  Ao chegar na última linha de cada matriz, o deslocamento é apenas para direita até chegar na última posição.<br/>
  O caminhamento é dado pela última direção visitada que cumpri os critérios abordados. Em casos com números iguais, a escolha é feita sempre pelo último comando que o algoritmo entrou, de acordo com a ordem de verificação apresentada.
 
 
- ```Função resultado``` : Ao final da execução do código é revelado a soma total do percurso de todas as matrizes juntas.
- ```Função imprimir``` : Responsável por mostrar a matriz.

 ## Tempo de execução

 A contagem foi feita pelas ferramentas disponibilizadas pela bibioteca "time.h". <br/>
 A média geral do tempo de execução deste código é: 0,0026097 segundos.



## Resultados

Durante a execução do programa é mostrado: 
No final, a heap conterá os k elementos com maiores valores (frequências) da coleção
de dados. Então, imprima-os em ordem crescente.

### **Conclusão**

Ao realizar o projeto de Labirinto Recorrente, foi possível explorar novas técnicas de programação, incluindo a utilização de estruturas de dados para representar um labirinto em forma de matriz. Percebe-se a importância de otimizar o código para garantir um desempenho satisfatório ao usar a estratégia randômica, que se torna um grande desafio devido à imprevisibilidade das escolhas e à enorme variedade de resultados possíveis.  <br/>
A solução acresenta ainda, ferramentas que façam um eficiente uso da memória, para que diante uma enorme entrada de dados, não seja necessário armazenar espaços em excesso e não ultrapassar o limite, dessa forma evitando a perca de desempenho ou travamento do código. <br/>
Portanto, observa-se como uma oportunidade de melhoria considerar possibilidades de erros e situações imprevistas que o algoritmo possa encontrar, pois como o andamento geral do programa é aleatório existem inúmeras formas de testar a eficiência do algoritmo, assim desenvolver mais procedimentos para garantir que se possa lidar com essas situações de uma maneira mais segura. 


<img src="imagens/terminal.png" height="550" width="350">


### Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. <br/>Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


- [Referências](#Referências)
- [Compilação e execução](#Compilação-e-execução)
- [Contato](#Contato)