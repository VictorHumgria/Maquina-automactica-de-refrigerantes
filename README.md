# Máquina Automática de Refrigerantes

Este projeto é uma simulação de uma máquina automática de venda de refrigerantes, escrita em linguagem C, que utiliza diversos algoritmos e técnicas de programação, como programação dinâmica, backtracking e divisão e conquista. O programa permite gerenciar o estoque de refrigerantes, efetuar vendas, calcular troco utilizando diferentes algoritmos e salvar os dados em um arquivo JSON.

## Índice

- [Funcionalidades](#funcionalidades)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Requisitos](#requisitos)
- [Instalação](#instalação)
- [Compilação e Execução](#compilação-e-execução)
- [Configuração do Visual Studio Code](#configuração-do-visual-studio-code)
- [Uso](#uso)
- [Contribuição](#contribuição)
- [Licença](#licença)

## Funcionalidades

- **Compra de Refrigerantes**: O usuário pode selecionar um refrigerante para comprar, efetuar o pagamento e receber o troco calculado por diferentes algoritmos.
- **Gestão de Estoque**: Permite adicionar novos refrigerantes ao estoque, repor estoque de produtos com baixa quantidade e exibir o estoque atual.
- **Cálculo de Troco**:
  - **Algoritmo Guloso**: Calcula o troco usando o menor número possível de moedas de maior valor.
  - **Programação Dinâmica**: Calcula o troco usando o menor número possível de moedas considerando todas as combinações.
- **Encontrar Combinações de Produtos**: Utiliza backtracking para encontrar combinações de refrigerantes que somam um valor específico.
- **Persistência de Dados**: Salva e carrega o estoque de refrigerantes em um arquivo JSON usando a biblioteca cJSON.
- **Interface Gráfica no Console**: Apresenta menus e informações formatadas para melhor experiência do usuário.

## Estrutura do Projeto

O projeto está modularizado nos seguintes arquivos:

- **Headers (.h)**:
  - `refrigerante.h`: Define a estrutura `Refrigerante`.
  - `interface.h`: Declara funções relacionadas à interface gráfica.
  - `estoque.h`: Declara funções para gerenciamento de estoque.
  - `pagamento.h`: Declara funções relacionadas ao processamento de pagamentos.
  - `algoritmos.h`: Declara funções dos algoritmos utilizados.
  - `persistencia.h`: Declara funções para salvar e carregar dados.

- **Implementações (.c)**:
  - `main.c`: Função principal que coordena o programa.
  - `interface.c`: Implementa funções de interface gráfica.
  - `estoque.c`: Implementa funções de gerenciamento de estoque.
  - `pagamento.c`: Implementa funções de pagamento.
  - `algoritmos.c`: Implementa os algoritmos para cálculo de troco e combinações.
  - `persistencia.c`: Implementa funções de persistência de dados.
  - `cJSON.c`: Biblioteca para manipulação de arquivos JSON (deve ser incluída no projeto).

## Requisitos

- **Compilador C**: GCC compatível com C99.
- **Biblioteca cJSON**: Necessária para manipulação de arquivos JSON.
- **Visual Studio Code**: Para facilitar a compilação e depuração (opcional).
- **Extensões do VSCode**:
  - **C/C++** (Microsoft): Para suporte a desenvolvimento em C/C++.
- **Sistema Operacional**: Windows, Linux ou macOS.

## Instalação

1. **Clonar o Repositório**:

   ```bash
   git clone https://github.com/seu-usuario/seu-repositorio.git
   ```

2. **Navegar para o Diretório do Projeto**:

   ```bash
   cd seu-repositorio
   ```

3. **Instalar a Biblioteca cJSON**:

   - Baixe a biblioteca cJSON do repositório oficial: [https://github.com/DaveGamble/cJSON](https://github.com/DaveGamble/cJSON)
   - Copie os arquivos `cJSON.h` e `cJSON.c` para o diretório do projeto.

## Compilação e Execução

### Compilação Manual via Terminal

No terminal, execute o seguinte comando para compilar o programa:

```bash
gcc -o maquinaAutomatica main.c interface.c estoque.c pagamento.c algoritmos.c persistencia.c cJSON.c -Wall -Wextra -Werror -std=c99
```

Após a compilação bem-sucedida, execute o programa:

```bash
./maquinaAutomatica   # No Linux/macOS
maquinaAutomatica.exe # No Windows
```

### Compilação Usando Script

Um script `compilar.sh` está disponível para facilitar a compilação.

1. **Tornar o Script Executável**:

   ```bash
   chmod +x compilar.sh
   ```

2. **Executar o Script**:

   ```bash
   ./compilar.sh
   ```

## Configuração do Visual Studio Code

Para facilitar o desenvolvimento, você pode configurar o VSCode para compilar e depurar o programa.

### 1. Configurar Tarefa de Compilação (`tasks.json`)

Crie um arquivo `.vscode/tasks.json` com o seguinte conteúdo:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compilar Máquina Automática",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-g",
                "-o",
                "maquinaAutomatica",
                "main.c",
                "interface.c",
                "estoque.c",
                "pagamento.c",
                "algoritmos.c",
                "persistencia.c",
                "cJSON.c",
                "-Wall",
                "-Wextra",
                "-Werror",
                "-std=c99"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared",
                "showReuseMessage": true,
                "clear": true
            },
            "problemMatcher": "$gcc"
        }
    ]
}
```

### 2. Configurar Depuração (`launch.json`)

Crie um arquivo `.vscode/launch.json` com o seguinte conteúdo:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Depurar Máquina Automática",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/maquinaAutomatica",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Ativar impressão aprimorada",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "Compilar Máquina Automática"
        }
    ]
}
```

**Nota**: No Windows, altere `"program"` para `${workspaceFolder}/maquinaAutomatica.exe` e especifique o caminho para o `gdb.exe` em `"miDebuggerPath"`.

### 3. Compilar e Depurar no VSCode

- **Compilar**: Pressione `Ctrl+Shift+B` e selecione **Compilar Máquina Automática**.
- **Depurar**: Pressione `F5` para iniciar a depuração.

## Uso

Ao executar o programa, você verá um menu interativo com as seguintes opções:

1. **Efetuar Compra**: Permite comprar um refrigerante, efetuar o pagamento e receber o troco.
2. **Adicionar Refrigerante**: Adiciona um novo refrigerante ao estoque.
3. **Repor Estoque**: Repõe o estoque de refrigerantes com quantidade baixa.
4. **Encontrar Combinação**: Encontra combinações de refrigerantes que somam um valor específico.
5. **Exibir Estoque**: Mostra o estoque atual de refrigerantes.
0. **Sair**: Encerra o programa.

### Exemplo de Uso

1. **Efetuar Compra**:

   - Selecione a opção `1`.
   - Escolha o refrigerante desejado.
   - Insira o valor do pagamento.
   - Escolha o método para calcular o troco (Algoritmo Guloso ou Programação Dinâmica).
   - O troco será calculado e exibido.

2. **Adicionar Refrigerante**:

   - Selecione a opção `2`.
   - Insira o nome, preço e quantidade do novo refrigerante.

3. **Repor Estoque**:

   - Selecione a opção `3`.
   - O programa verificará os produtos com estoque baixo e solicitará a quantidade para reposição.

4. **Encontrar Combinação**:

   - Selecione a opção `4`.
   - Insira o valor que deseja gastar.
   - O programa exibirá todas as combinações possíveis de refrigerantes que somam o valor especificado.

## Contribuição

Contribuições são bem-vindas! Sinta-se à vontade para abrir **issues** ou enviar **pull requests** com melhorias, correções de bugs ou novas funcionalidades.

Para contribuir:

1. **Fork** o repositório.
2. Crie uma **branch** com a nova funcionalidade: `git checkout -b minha-nova-funcionalidade`.
3. **Commit** suas alterações: `git commit -m 'Adicionar nova funcionalidade'`.
4. **Push** para a branch: `git push origin minha-nova-funcionalidade`.
5. Abra um **Pull Request**.

## Licença

Este projeto está licenciado sob a licença MIT - veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

**Nota**: Este projeto é uma simulação educacional e não deve ser utilizado em ambientes de produção sem as devidas adaptações e verificações de segurança.

---

**Autor**:  - JOAO VICTOR MENESES SOUZA
            - JOAO VICTOR SILVA DE HUNGRIA
            - RENNE BISPO DOS SANTOS
            - TALYSSON FELIPE VASCONCELOS SANTOS
