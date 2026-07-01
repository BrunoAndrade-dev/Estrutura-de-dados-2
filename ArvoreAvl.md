O código anterior já incluía as rotações à esquerda e as rotações duplas! No entanto, reestruturei e expandi ainda mais as explicações visuais de cada uma delas dentro do bloco de código abaixo.

Aqui está o conteúdo completo, detalhado passo a passo com todos os 4 casos (Simples à Direita, Simples à Esquerda, Dupla à Direita e Dupla à Esquerda), pronto para copiar:

```markdown
# 🌳 Entendendo Árvores AVL e Balanceamento

Bem-vindo a este guia prático e didático sobre **Árvores AVL**! Se você já se perguntou por que precisamos de árvores auto-balanceáveis e como funcionam as rotações (simples e duplas), este documento vai clarear tudo.

---

## 📌 O que é uma Árvore AVL?

Uma **Árvore AVL** (Adelson-Velsky e Landis) é uma **Árvore Binária de Busca (BST)** auto-balanceada. 

Numa BST comum, se inserirmos elementos já ordenados (ex: 1, 2, 3, 4, 5), a árvore vira essencialmente uma lista encadeada. Isso faz com que o tempo de busca piore de $O(\log n)$ para $O(n)$. A AVL resolve isso garantindo estabilidade e simetria após cada inserção ou remoção.

---

## ⚖️ O Fator de Balanceamento (FB)

O segredo do ecossistema AVL é o **Fator de Balanceamento (FB)**, calculado para cada nó individualmente:

$$\text{FB} = \text{altura}(\text{subárvore esquerda}) - \text{altura}(\text{subárvore direita})$$

> 💡 **Regra de Ouro da AVL:** Em qualquer nó, o FB deve ser estritamente **-1, 0 ou 1**. 
> Se o FB chegar a $\le -2$ ou $\ge 2$, a árvore está desbalanceada e uma **Rotação** deve ser executada imediatamente.

---

## 🔄 Tipos de Balanceamento: As Rotações

Dependendo de como o desbalanceamento ocorre, aplicamos **Rotações Simples** ou **Rotações Duplas**.

### 1. Rotações Simples
Usadas quando o desbalanceamento acontece em linha reta (linear).

#### A. Rotação Simples à Direita (Caso Esquerda-Esquerda / EE)
Ocorre quando um nó é inserido na subárvore **esquerda** do filho **esquerdo**. A árvore pesa totalmente para a esquerda.

* **Como resolver:** O nó do meio (B) "sobe" para virar a nova raiz, e o nó desbalanceado (C) desce para a direita.

```text
       C (FB: +2)          B
      /                   / \
     B (FB: +1)   -->    A   C
    /
   A (FB: 0)

```

#### B. Rotação Simples à Esquerda (Caso Direita-Direita / DD)

Ocorre quando um nó é inserido na subárvore **direita** do filho **direito**. A árvore pesa totalmente para a direita.

* **Como resolver:** O nó do meio (B) "sobe" para virar a nova raiz, e o nó desbalanceado (A) desce para a esquerda.

```text
   A (FB: -2)              B
    \                     / \
     B (FB: -1)   -->    A   C
      \
       C (FB: 0)

```

---

### 2. Rotações Duplas

Usadas quando o desbalanceamento ocorre em formato de "ziguezague" (um joelho). Uma única rotação simples não resolve o problema, por isso combinamos duas.

#### A. Rotação Dupla à Direita (Caso Esquerda-Direita / ED)

Ocorre quando inserimos um elemento na subárvore **direita** do filho **esquerdo**.

* **Passo 1:** Fazemos uma Rotação Simples à **Esquerda** no filho (nó A). O ziguezague vira uma linha reta (caso EE).
* **Passo 2:** Fazemos uma Rotação Simples à **Direita** no nó principal desbalanceado (nó C).

```text
     C (FB: +2)             C (FB: +2)             B
    /                      /                      / \
   A (FB: -1)    -->      B (FB: +1)     -->     A   C
    \                    /
     B (FB: 0)          A (FB: 0)

```

#### B. Rotação Dupla à Esquerda (Caso Direita-Esquerda / DE)

Ocorre quando inserimos um elemento na subárvore **esquerda** do filho **direito**.

* **Passo 1:** Fazemos uma Rotação Simples à **Direita** no filho (nó C). O ziguezague vira uma linha reta (caso DD).
* **Passo 2:** Fazemos uma Rotação Simples à **Esquerda** no nó principal desbalanceado (nó A).

```text
   A (FB: -2)           A (FB: -2)                 B
    \                    \                        / \
     C (FB: +1)  -->      B (FB: -1)     -->     A   C
    /                      \
   B (FB: 0)                C (FB: 0)

```

---

## 🛠️ Tabela de Tomada de Decisão (Resumo)

Para saber qual rotação aplicar, encontre o primeiro nó desbalanceado (FB = +2 ou -2) de baixo para cima e olhe o sinal do FB dele e do seu filho:

| FB do Nó Desbalanceado | FB do Filho Direto | Tipo de Caso | Rotação a Aplicar |
| --- | --- | --- | --- |
| **+2** | **+1** | Esquerda-Esquerda (EE) | Rotação Simples à Direita |
| **-2** | **-1** | Direita-Direita (DD) | Rotação Simples à Esquerda |
| **+2** | **-1** | Esquerda-Direita (ED) | Rotação Dupla à Direita (Esquerda no filho -> Direita no pai) |
| **-2** | **+1** | Direita-Esquerda (DE) | Rotação Dupla à Esquerda (Direita no filho -> Esquerda no pai) |

---

## 🚀 Conclusão

O custo computacional de calcular alturas e rotacionar nós durante as inserções compensa drasticamente a longo prazo. Graças a esse mecanismo, a árvore AVL garante que qualquer busca, inserção ou remoção termine sempre no tempo estável de:

$$O(\log n)$$

---

⚡ *Guia prático para referência rápida em Estruturas de Dados.*

```

```