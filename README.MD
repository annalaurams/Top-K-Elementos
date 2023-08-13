# **Top K Elementos**

Atividade para a disciplina de Algoritmos e Estruturas de Dados II. <br/>

## Sumário

- [Objetivos](#Objetivos)
- [Estrutura](#Estrutura)
- [Diretrizes](#Diretrizes)
- [Decisões_de_Implementação](#Decisões_de_Implementação)
- [Funções](#Funções)
- [Tempo_de_execução_e_Custo_computacional](#Tempo_de_execução_e_Custo_computacional)
- [Resultados](#Resultados)
- [Conclusão](#Conclusão)
- [Referências](#Referências)
- [Compilação e execução](#Compilação-e-execução)
- [Contato](#Contato)


## Objetivo

O objetivo é desenvolver um algoritmo utilizando-se tabela hash e o método heap sort para resolver um problema clássico chamado top k itens. 
Neste tipo de problema é preciso encontrar os k itens mais valiosos de uma coleção de dados. Logo, utiliza-se o hash para contar a frequência de todos os itens, enquanto o heap se aplica na manutenção de uma lista dos k itens de maior valor. 

## Estrutura

- topk.hpp: Engloba a struct, todas as funções utilizadas e seus parâmetros.
- topk.cpp: Contém a criação e o desenvolvimento de todas as funções usadas.    
- main.cpp: Pertence a parte de leitura dos arquivos, chamada das funções necessários para o funcionamento do código e seu tempo de execução.
- include.hpp: Inclui biliotecas e arquivos a serem utilizados no programa.
- text1.txt: Texto de entrada. 
- text2.txt: Texto de entrada. 
- stopwords.txt: Artigos e conjunções como (a, o, as, os, e, ou).

## Diretrizes

As especificações a seguir foram propostas para discussão e resolução do problema:

A partir de um texto de entrada, o algoritmo realiza a leitura dele e cria uma tabela de dispersão (hash) intitulada glossary, para contar quantas vezes cada palavra aparece no texto.
A chave do hash é a própria palavra.
As stopWords lidas do arquivo que estiverem contidas no glossário são excluídas do glossário.
Em seguida, a partir de um valor k, é inserido em um vetor heap os primeiros k elementos guardados no hash e depois são ordenados de forma crescente em relação as ocorrências.
Depois para os elementos restante no hash

Após isso para cada elemento restante na hash, é realizado comparações com o menor valor contifo no heap, que está na primeira posição.

Se a ocorrência for maior do que o menor valor da heap, o menor vaor é removido, o novo elemento é inserido e a estrutura novamente ordenada.
3. Caso contrário, ignore o elemento e vá para o próximo, até o fim do glossário.
• No final, a heap conterá os k elementos com maiores valores (ocorrências) dentre os textos lidos. Então, são imprimidos em ordem crescente.

• Este programa deverá ler uma coleção de arquivos contento textos sem nenhuma for-
matação ("arquivo ASCII") onde cada sentença termina por um sinal de pontuação (".",
"?", "!"").
• Cada parágrafo é separado por, pelo menos, uma linha em branco.
• Considere como palavra uma sequência de letras delimitada por espaço em branco, ”col-
una da esquerda”, ”coluna da direita” e símbolos de pontuação.

O programa permite a leitura de vários arquivos de texto ao mesmo tempo, no entanto existem algumas regras:
Para cada novo arquivo que se deseja ler, deve ser colocado dentro da pasta ```data```. O nome dos arquivos de texto seguem um padrão de "text1.txt" (1° arquivo), "text2.txt"(2° arquivo) e assim sucessivamente, logo devem ser renomeados. Além disso, a variável ```FILES``` dentro do ```include.hpp``` guarda a quantidade de arquivos a serem lidos, portanto, modifique para a quantidade desejada.

O programa contém um arquivo de stopWords, que podem ser alteradas de acordo com a preferência do usuário. O conteúdo deste arquivo é salvo em outra tabela de dispersão e as palavras dele são identificadas no texto, e em seguida excluídas. Pois, por serem artigos e conjunções facilmente seriam as mais frequentes do heap, no entanto foram desconsideradas.

Dentro do arquivo ```include.hpp```possui a variável K que corresponde ao tamanho do heap, também pode ser alterada.

## Decisões de implementação

Estruturas escolhidas:  Unordered_map, vector e heapSort 

unordered_map: Implementado usando a tabela de hash, o qual tem uma função de hash para calcular o índice de armazenamento de cada elemento, permitindo um acesso direto aos dados, sem a necessidade de percorrer todos os eles, ela armazena chave e valor, que nesse caso representa a palavra e sua ocorrência. O unordered_map não mantém os elementos ordenados.


Alguns benefícios de usar essas estruturas são: rapidez em acessas elementos e a capacidade de armazenar enormes entradas de dados.

Heapsort: Utiliza uma estrutura de dados chamada "heap" para organizar os elementos, é como uma árvore binária mantida na forma de um vetor.. Neste caso o heap construído guarda o menor elemento no início.

Alguns benefícios de usar essas estruturas são: Eficientes para grandes entradas de dados.

O método heapify funciona da seguinte forma:

Começa no último pai da árvore, que é o elemento no meio do array.
Verifica se o pai é maior ou igual aos seus dois filhos. Se não for, troca o pai com o filho maior.
Continua movendo para cima na árvore, verificando e trocando os pais com seus filhos maiores, até que chegue ao topo da árvore.
No final do algoritmo, o array estará convertido em um heap.

O método heapify é usado no algoritmo de ordenação heapsort. O heapsort funciona criando um heap a partir do array original e, em seguida, removendo os elementos do heap em ordem crescente.

<div style="text-align:center">
  <video width="400" height="400" controls>
    <source src="img/exemplo.mp4" type="video/mp4">
  </video>
</div>

 ## Funções

- ```addStopWord``` : Adiciona as stop words no glossário destinado para elas.
- ```existentWord```: Verifica as stop words presente no glossário e remove elas dele.

- ```manyFiles```: Guarda o nome dos arquivos dos textos de entrada em um vector.

- ```printGlossary``` : Imprimi o glossário de palavras de ambos os textos.
- ```fileReading``` : Realiza leitura caracter por caracter dos textos de entrada, utilizando um switch case, essa função processa, identifica as palavras e adiciona cada uma no glossário.
- ```cases``` : Realiza a contagem de ocorrência de cada palavra a medida que o texto é lido.
- ```Accentuation``` : Procedimento que trata palavras acentuadas para aparecerem corretamente.
- ```removeErro``` : Exclui possíveis strings vazias do glossário.
- ```insertK``` : Insere os primeiros k elementos do hash no heap.
- ```printHeap``` : Imprimi o heap de forma crescente.

- ```finaleHash``` : Realiza inserção do restante dos itens do hash, a partir da posição K, insere ou troca as maiores ocorrências do heap.
- ```heapify``` : Responsável por garantir que o valor no nó seja maior ou igual aos valores de seus filhos. 
- ```heapSort``` : Ordena o heap de maneira crescente.




 ## Tempo de execução e Custo Computacional

A contagem foi feita pelas ferramentas disponibilizadas pela bibioteca "time.h". <br/>
A média geral do tempo de execução deste código é: 

Unordered_map:

Heapsort: O(nlogk), onde n é o tamanho da coleção de dados e k o número de itens mais relevantes.

## Resultados

Ao final da execução é mostrado o heap com as palavras com as maiores ocorrências da coleção de dados, em ordem crescente.



### **Conclusão**

Ao realizar o projeto "Top K itens", foi possível explorar técnicas de programação utilizando estruturas como o tabela hash e o método heap, para grande entradas de dados.
Esse algoritmo é uma combinação eficiente do uso de hash para contar a frequência dos elementos e heap para manter a lista dos k elementos com maiores valores.
Ao combinar as capacidades de contagem rápida de hash e a capacidade de manutenção de ordem e seleção eficiente de heap, o algoritmo consegue atingir um desempenho notável em termos de complexidade temporal.

<img src="imagens/terminal.png" height="550" width="350">


### Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. <br/>Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |



### Contato

<div>
 <br><p align="justify"> Anna Laura Moura Santana</p>
 <a href="https://t.me/annalaurams">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:nalauramoura@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>nalauramoura@gmail.com</i>
</a>