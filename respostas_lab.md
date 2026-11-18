# Anotacoes da Parte B e Discussao (Unidade 6)

## Questao L1 (Gerador de IDs com static)
* **O que muda se tirar o `static`?**
  Sem o `static`, o programa passa a imprimir `1 1 1 1 1` em vez de `1 2 3 4 5`. Isso acontece porque a variavel deixa de ficar na area de dados estaticos e vira uma variavel local comum na pilha (stack), sendo criada e iniciada com zero toda vez que a funcao e chamada.

## Questao L3 (Devolvendo memoria alocada na funcao)
* **Por que aqui devolver o ponteiro funciona e no item 4 da Parte A dava erro? Quem faz o `free`?**
  Aqui o vetor foi criado no heap usando `malloc`, e essa regiao continua valida mesmo depois que a funcao termina, so sendo liberada quando `free` e chamado. Ja no item 4, a variavel era local da pilha e sumia assim que a funcao acabava. Quem tem a responsabilidade de chamar `free` e a funcao `main`, que recebeu o ponteiro retornado.

## Questao L4 (Vazamento de memoria)
* **Da para notar o vazamento so executando o programa? Quantos bytes vazaram?**
  Nao da para notar apenas rodando no terminal, porque o programa encerra normalmente e o sistema operacional limpa toda a memoria do processo ao final. O problema so apareceria sem ferramenta se fosse um programa que ficasse rodando por muito tempo alocando sem parar. No exemplo original vazaram **4000 bytes** (`1000 * 4` bytes de cada `int`).

## Questao L5 (Acesso depois do free)
* **Qual a diferenca entre esse erro e o vazamento do L4?**
  No L5 (`heap-use-after-free`), o programa devolveu o bloco com `free`, mas tentou ler uma posicao dele logo depois, acessando memoria que nao pertence mais a ele. No L4 (`memory leak`), acontece o oposto: o programa nunca chama `free` e deixa o bloco preso sem uso ate encerrar.

## Discussao final da unidade
* **Quais problemas o compilador detecta sozinho e quais so aparecem rodando ou com ferramentas?**
  * **Detectados na compilacao (`-Wall -Wextra`):**
    * **Item 12 (Parte A):** erro de compilacao por tentar usar `i` e `dobro` fora do bloco `for` onde foram declarados.
    * **Item 4 (Parte A):** aviso (`warning`) por tentar retornar o endereco `&x` de uma variavel local da pilha.
  * **Detectados apenas na execucao ou com AddressSanitizer / Valgrind:**
    * **Itens 1, 2, 7 (Parte A) e L1:** falhas de logica por esquecer `static`, ja que a sintaxe esta certa, mas o valor reinicia a cada chamada.
    * **Itens 6, 8, 11 (Parte A), L4 e L5:** problemas de gerenciamento dinamico no heap, como esquecer o `free` (vazamento), ler memoria depois de liberar (`use-after-free`) e chamar `free` duas vezes no mesmo ponteiro (`double free`).
