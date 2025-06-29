# TEORIA

---

**Segurança da Encriptação**: a segurança da cifra depende do segredo da **chave** e não do algoritmo. O algoritmo é público, a **chave** é secreta.

## Atacantes
- **Atacante Passivo**: escuta a comunicação entre duas partes, mas não interfere na comunicação. O atacante tenta obter a mensagem original.
- **Atacante Ativo**: escuta a comunicação entre duas partes e interfere na comunicação. O atacante tenta obter a mensagem original e alterar a mensagem cifrada.

- **Atacante computacionalmente limitado**: apenas consegue aplicar um certo número de algoritmos.
- **Atacante computacionalmente ilimitado**: consegue aplicar qualquer algoritmo sem qualquer limite a nível de memória ou tempo.

---

## 1. Classical Ciphers

- **Cifra de César**: uma das mais simples e conhecidas, onde cada letra é deslocada um número fixo de posições no alfabeto. Sensível a ataques de força bruta.
- **Cifra de Vigenère**: utiliza uma palavra-chave para determinar o deslocamento de cada letra, tornando-a mais segura que a cifra de César. 
- **OTP**: um método de criptografia que utiliza uma chave única e aleatória do mesmo comprimento que a mensagem e que é utilizada apenas uma única vez, garantindo segurança perfeita. 

---

## 2. Segurança

**Propriedades**:
- **Confidencialidade**: apenas o destinatário pode ler a mensagem.
- **Integridade**: a mensagem não foi alterada durante a transmissão.
- **Autenticidade**: o remetente é quem diz ser.
- **Não repúdio**: o remetente não pode negar que enviou a mensagem.
- **Disponibilidade**: a mensagem está disponível para o destinatário sempre que necessário.
- **Anonimidade**: o remetente não pode ser identificado.
---

## 3. Criptografia Simétrica
Stream ciphers + block ciphers + one way functions + key management.
### 3.1 Stream Ciphers
Basicamente um XOR entre a mensagem e uma chave. A chave é gerada a partir de um algoritmo que gera uma sequência de bits pseudo-aleatória. O algoritmo é conhecido, mas a chave é secreta.

Podem ser:
- **Síncronos**: a chave é gerada de forma síncrona com a mensagem => keystream independente da mensagem. Perda resulta na perda de sincronismo.
- **Self-síncrono**: capaz de recuperar o sincronismo quando um bit é perdido. É necessário um vetor de inicialização (IV) para garantir que a chave é única para cada mensagem. O IV é enviado junto com a mensagem cifrada. Vulnerável a ataques de repetição.


É necessário utilizarmos um NONCE (número usado uma vez) para garantir que a chave é única para cada mensagem. O NONCE é enviado junto com a mensagem cifrada.

Exemplo de stream cipher: RC4 e Chacha20.


### 3.2 Block Ciphers

Block ciphers dividem a mensagem em blocos de tamanho fixo e aplicam uma função de encriptação a cada bloco. O block cipher mais conhecido é o AES (Advanced Encryption Standard), que utiliza blocos de 128 bits e chaves de 128, 192 ou 256 bits.
A cifra de bloco é mais segura que a cifra de fluxo, pois não depende da sincronização entre o remetente e o destinatário. No entanto, é mais lenta e requer mais recursos computacionais.

**AES: confidencialidade apenas!**

**<span style="color:red">Obs:</span>** Stream ciphers são mais rápidos que block ciphers, mas menos seguros. Block ciphers são mais seguros, mas mais lentos.

Existem dois designs distintos para block ciphers:
- **Diffusion**: garante que uma pequena alteração na mensagem resulta numa grande alteração no ciphertext. Isto é conseguido através de substituições e permutações.
- **Confusion**: garante que a relação entre a chave e o ciphertext é complexa e não linear. Isto é conseguido através de operações matemáticas complexas, como multiplicação e adição.


**Padding**:
Para cifrar mensagens de tamanho variável, é necessário adicionar padding aos blocos para que tenham o tamanho correto, uma vez que alguns modos de operação requerem que o tamanho da mensagem seja um múltiplo do tamanho do bloco. O padding mais comum é o PKCS#7, que adiciona bytes com o valor do número de bytes de padding.

**Modos de operação**:
- **ECB (Electronic Codebook)**: cada bloco é cifrado de forma independente. Vulnerável a ataques de repetição e análise de frequência, pois blocos idênticos resultam em blocos cifrados idênticos. Requer padding. Deve ser apenas utilizado para cifrar mensagens de tamanho equivalente ao tamanho de um bloco.
- **CBC (Cipher Block Chaining)**: cada bloco é cifrado com o bloco anterior (dependência), garantindo que blocos idênticos resultem em blocos cifrados diferentes (XOR). Utiliza um vetor de inicialização (IV) para o primeiro bloco, que deve ser único e aleatório para cada mensagem. O IV é enviado junto com a mensagem cifrada. Desencriptação pode ser feita em paralelo, mas a encriptação não pode. O último bloco pode ser um *CBC-MAC*, que é uma assinatura digital do bloco anterior, ou seja, o último bloco é cifrado com a chave e o bloco anterior, garantindo a integridade da mensagem. Isto pois, qualquer mudança nos bits do plaintext fazem com que o ciphertext seja alterado de forma completamente não previsível
- **CFB (Cipher Feedback)**: semelhante ao CBC, mas permite cifrar mensagens de tamanho variável. Utiliza um vetor de inicialização (IV) para o primeiro bloco, que deve ser único e aleatório para cada mensagem (funciona como um NONCE). O IV é enviado junto com a mensagem cifrada. O XOR acontece depois. Implementa um stream cipher auto-síncrono, onde o cifrador é alimentado com o ciphertext do bloco anterior. Isto permite que a cifra de bloco seja usada como uma cifra de fluxo, mas com a segurança adicional de que blocos idênticos resultam em blocos cifrados diferentes. Não necessita de padding, pois a cifra de bloco é aplicada a um vetor de inicialização (IV) e não aos blocos da mensagem. O keystream depende da chave, do IV e do plaintext anterior.
- **OFB (Output Feedback)**: semelhante ao CFB, mas a cifra de bloco é aplicada a um vetor de inicialização (IV), que deve ser uma espécie de NONCE, e não aos blocos da mensagem.
  - síncrono;
  - não necessita de padding;
  - o keystream nao depende do plaintext anterior;
- **CTR (Counter)**: utiliza um contador para gerar uma sequência de bits pseudo-aleatória, que é XORed com a mensagem. O contador é incrementado para cada bloco, garantindo que blocos idênticos resultem em blocos cifrados diferentes. O contador é enviado junto com a mensagem cifrada.
  - síncrono;
  - não necessita de padding;
  - o keystream não depende do plaintext anterior;

**<span style="color:orange">Authenticated Encryption (AE)</span>**

Modos de operação que garantem a **autenticidade**, **confidencialidade** e **integridade** da mensagem cifrada, como o GCM (Galois/Counter Mode) e o CCM (Counter with CBC-MAC). Estes modos de operação utilizam uma função de autenticação para garantir que a mensagem não foi alterada durante a transmissão.

**<span style="color:grey">Advanced Encryption Standard (AES)</span>**

AES é um algoritmo de cifra de bloco que utiliza chaves de 128, 192 ou 256 bits e blocos de 128 bits. É amplamente utilizado em aplicações de segurança, como VPNs, TLS e criptografia de disco.

### 3.3 One-Way Functions
Funções unidirecionais são funções matemáticas que são fáceis de calcular, mas difíceis de inverter. São utilizadas em criptografia para garantir a **integridade** e **autenticidade** das mensagens. Hash functions por si só não garantem integridade.

Exemplos: SHA-256, SHA-3, BLAKE2.

**Message Authentication Codes (MACs)**:
MACs são códigos de autenticação de mensagem que garantem a **integridade** e **autenticidade** das mensagens. São gerados a partir de uma função unidirecional e uma chave secreta. O código gerado é baseado num segredo secreto que apenas as partes legítimas (remetente e destinatário) conhecem.

Exemplo: Poly1305, CMAC.

**HMACs** são utilizados em protocolos de segurança, como TLS e SSH, para garantir que as mensagens não foram alteradas durante a transmissão. Construção de um MAC a partir de uma função de hash. Neste caso, até são performadas duas passagens pela função, de forma a evitar ataques de length extension.

**Key-Derivation Functions (KDF)**:
Permitem a derivação de chaves a partir de material criptográfico secreto. Por exemplo, derivar uma chave a partir de uma *password* (baixa entropia e vulnerável a ataques de enumeração. Para minimizar tais problemas, deve ser utilizado um salt) ou *passphrase* ou até mesmo de um master secret acordado a partir de um protocolo de handshaking.
Exemplo: PBKDF2, bcrypt, scrypt.

salt - número aleatório adicionado à *password* antes de ser processada pela função de hash. O salt é enviado junto com o hash, permitindo que o destinatário verifique a *password* sem precisar conhecer o salt.

### 3.4 Key Management
A gestão de chaves é um aspecto crítico da criptografia simétrica. Envolve a geração, distribuição, armazenamento e revogação de chaves secretas. A segurança da criptografia simétrica depende da segurança das chaves secretas. Se uma chave secreta for comprometida, todas as mensagens cifradas com essa chave também serão comprometidas.

**Key handling**:
- O período de vida de uma chave deve ser o mais curto possível;
- static keys => long-term keys, que são utilizadas durante um período prolongado de tempo;
- ephemeral keys => session keys, que são utilizadas apenas durante uma sessão de comunicação;

As chaves não devem ser utilizadas para diversos propósitos, pois isso aumenta o risco de comprometimento. Por exemplo, uma chave utilizada para cifrar mensagens não deve ser utilizada para autenticar mensagens. Devemos utilizar KDFs para derivar chaves a partir de um master secret ou de uma *password*.

**CMKs** são sistemas de gestão de chaves que permitem a geração, distribuição, armazenamento e revogação de chaves secretas. Estes sistemas são utilizados para garantir a segurança das chaves secretas e para facilitar a gestão de chaves em ambientes complexos.

---
## 4. Criptografia Assimétrica
A criptografia assimétrica utiliza um **par de chaves**: uma **chave pública** e uma **chave privada**. A chave pública é utilizada para **cifrar** mensagens, enquanto a chave privada é utilizada para **decifrar** mensagens. A segurança da criptografia assimétrica depende da dificuldade de fatoração de números grandes.
A criptografia assimétrica é mais lenta que a criptografia simétrica, mas oferece vantagens em termos de segurança e gestão de chaves. É amplamente utilizada em protocolos de segurança, como TLS, SSH e PGP.

### 4.1 Key Agreement

Diffie-Hellman é um protocolo de troca de chaves que permite que duas partes estabeleçam um segredo compartilhado através de um canal inseguro. **<span style="color:red">Não garante autenticidade</span>**. O protocolo funciona da seguinte forma:

1. Definem-se parâmetros públicos: um número primo grande (p) e uma base (g), que é uma raiz primitiva módulo p.
2. Cada parte escolhe um número secreto privado (por exemplo, a e b).
3. São calculadas as chaves públicas:
  - Parte A: A = g^a mod p
  - Parte B: B = g^b mod p
4. As chaves públicas (A e B) são trocadas entre as partes.
5. Cada parte utiliza a sua chave privada e a chave pública recebida para calcular o segredo:
  - Parte A: s = B^a mod p
  - Parte B: s = A^b mod p

Como resultado, ambas as partes obtêm o mesmo valor s, que pode ser usado como chave de sessão para criptografia simétrica. Mesmo que um atacante intercepte as chaves públicas, sem conhecer os números privados não é possível derivar o segredo compartilhado.

O protocolo Diffie-Hellman é fundamental em muitas aplicações de segurança, embora seja importante aplicar autenticação adicional para prevenir ataques de intermediário.

### 4.2 Public-Key Cryptography
Chave pública para encriptar, chave privada para decriptar.
Garante confidencialidade e autenticidade (dependendo do algoritmo).

**Algoritmos**:
- **RSA (Rivest-Shamir-Adleman):** um dos algoritmos mais conhecidos e utilizados. Baseia-se na dificuldade de fatoração de números grandes. Utiliza chaves de 1024, 2048 ou 4096 bits. É amplamente utilizado em protocolos de segurança, como TLS e SSH. **<span style="color:green">Garante confidencialidade e autenticidade</span>**.
- **DSA (Digital Signature Algorithm):** utilizado para assinaturas digitais. Baseia-se na dificuldade do problema do logaritmo discreto. Utiliza chaves de 1024, 2048 ou 3072 bits. É utilizado em protocolos de segurança, como TLS e SSH. **<span style="color:green">Garante autenticidade, mas não confidencialidade</span>**. Mais eficiente que o RSA para assinaturas digitais, mas menos eficiente para cifragem.
- **ECDSA (Elliptic Curve Digital Signature Algorithm):** uma variante do DSA que utiliza curvas elípticas para gerar assinaturas digitais. É mais eficiente que o DSA e o RSA, pois utiliza chaves menores para o mesmo nível de segurança. É amplamente utilizado em protocolos de segurança, como TLS e SSH. **<span style="color:green">Garante autenticidade, mas não confidencialidade</span>**.
- **ElGamal:** utilizado para cifragem e assinaturas digitais. Baseia-se na dificuldade do problema do logaritmo discreto. É menos utilizado que o RSA e o DSA, mas ainda é relevante em algumas aplicações de segurança. **<span style="color:green">Garante confidencialidade e autenticidade</span>**.
- **ECC (Elliptic Curve Cryptography):** utiliza curvas elípticas para cifragem e assinaturas digitais. É mais eficiente que o RSA e o DSA, pois utiliza chaves menores para o mesmo nível de segurança. É amplamente utilizado em protocolos de segurança, como TLS e SSH. **<span style="color:green">Garante confidencialidade e autenticidade</span>**.

### 4.3 Paradigma KEM/DEM
O paradigma KEM/DEM (Key Encapsulation Mechanism/Data Encapsulation Mechanism) é uma abordagem híbrida que combina criptografia simétrica e assimétrica para garantir segurança e eficiência.
- **KEM (Key Encapsulation Mechanism)**: utiliza criptografia assimétrica para encapsular uma chave simétrica. A chave simétrica é gerada aleatoriamente e encapsulada com a chave pública do destinatário. O destinatário utiliza a sua chave privada para decapsular a chave simétrica.
- **DEM (Data Encapsulation Mechanism)**: utiliza a chave simétrica para cifrar os dados. A chave simétrica é utilizada para cifrar a mensagem, garantindo eficiência e velocidade na cifragem e decifragem dos dados.
Este paradigma é amplamente utilizado em protocolos de segurança, como TLS e SSH, para garantir a confidencialidade e autenticidade das mensagens. A combinação de criptografia simétrica e assimétrica permite que as partes estabeleçam um segredo compartilhado de forma segura e eficiente, aproveitando as vantagens de ambos os tipos de criptografia.

### 4.4 Assinaturas Digitais
As assinaturas digitais são uma forma de autenticação que utiliza criptografia assimétrica e garantem a  **<span style="color:green">integridade, autenticidade e não-repúdio</span>** das mensagens. Uma assinatura digital é gerada utilizando a chave privada do remetente e pode ser verificada utilizando a chave pública do remetente.

### 4.5 Infraestrutura de chave pública (PKI)
- Uma PKI é um sistema de hardware, software, políticas e procedimentos que gere, distribui, usa e amrazena chaves públicas e certificados digitais.

**X509**
- Apenas para autenticar chaves publicas

Este certificado inclui:
- Nome do proprietário (quem possui a chave privada associada à chave publica) 
- A chave publica
- Nome da entidade que emitiu o certificado (CA)
- Assinatura digital da CA

Esta informação é representada como atributo/valor (dicionário) e standarizada:
- DER (ASN.1 notation): formato binário;
- PEM: formato ASCII (base64) com cabeçalho e rodapé.

Atualmente os certificados utilizados sao X.509v3

Esta versão introduziu novos campos:
- Extensões: permitem adicionar novos campos ao certificado, como por exemplo:
  - Uso da chave: para que é que a chave publica pode ser usada (ex: assinatura digital, autenticação, etc);
  - Nome alternativo do sujeito: permite adicionar mais nomes ao certificado (ex: www.exemplo.com, mail.exemplo.com);
  - Autoridade de certificação: quem emitiu o certificado;
  - Lista de revogação de certificados (CRL): lista de certificados revogados.
  - Possui informação sobre o estado (crítica ou não crítica).

**PKIX**

Muitas entidades envolvidas numa PKI:
- Proprietários de certificados: quem requere um certificado para a sua chave publica;
- Clientes: quem usa a chave publica que contem o certificado;
- Autoridades de certificação (CAs): quem emite os certificados;
- Autoridades de registo (RAs): quem verifica a identidade do proprietário do certificado antes de o emitir;
- Repositórios: onde os certificados são armazenados e disponibilizados;

PKIX definiu um conjunto de especificações e protocolos permitindo:
- Sistemas/aplicação que efetivamente confiem em certificados X.509 (procotolos operacionais);
- gestão de PKI - operações de emissão, revogação e renovação de certificados;

### 4.6 Certificados

**Estrutura**:
- versão
- número de série
- sujeito
- emissor
- subject public key info
- assinatura
- validade
- extensões
  - uso da chave: restringe o uso da chave publica
  - basic contraints: define se a chave publica é uma CA ou não

**Criação de certificados**:
Um certificado é criado por uma autoridade de certificação (CA) que assina digitalmente a chave pública do proprietário do certificado. A assinatura digital é feita utilizando a chave privada da CA, garantindo que o certificado é autêntico e não foi alterado. O certificado contém a chave pública do proprietário, o nome do proprietário, o nome da CA, a validade do certificado e outras informações relevantes.

**Utilização de certificados**:
Quando a Alice necessita de enviar a sua chave pública para o Bob, ela envia o seu certificado, que contém a sua chave pública e é assinado pela CA. O Bob verifica a assinatura do certificado utilizando a chave pública da CA, garantindo que o certificado é autêntico e não foi alterado. Se a assinatura for válida, o Bob pode confiar na chave pública da Alice contida no certificado e utilizá-la para cifrar mensagens destinadas à Alice.
Os certificados são utilizados para garantir a autenticidade e integridade das chaves públicas, permitindo que as partes confiem nas chaves públicas umas das outras sem a necessidade de um canal seguro pré-estabelecido.

Os certificados sao sempre utilizados aquando da partilha da chave publica. A chave publica é sempre acompanhada de um certificado.
Cerficados sem CA são auto-assinados (self-signed). A chave publica é assinada pela própria entidade que a possui. Este tipo de certificado não é confiável, pois não existe uma terceira parte que o valide. Issuer = subject.

**Validação**
Para cada certificado, o cliente tem de verificar:
- Assinatura: verificar se a assinatura do certificado é válida (assinar com a chave publica da CA);
- A aplicação do certificado: verificar se o certificado é aplicável à chave publica (verificar se o subject corresponde ao nome do servidor);

**Trust Anchors**
O utilizador sabe um numero limitado de chaves publicas que pertençam a entidades de confiança (CA) que atuam como as raízes de confiança.
Normalmente é o sistema operativo que gere a lista de CA de confiança. A compilação e atualização é feita pelo SO.

### 4.7 Protocolo Station-to-Station (STS)
O protocolo Station-to-Station (STS) é um protocolo de troca de chaves que permite que duas partes estabeleçam um segredo compartilhado de forma segura, garantindo a autenticidade e integridade das mensagens. O protocolo é baseado na troca de mensagens cifradas utilizando criptografia assimétrica e criptografia simétrica.

## 6. Communication protocols (TLS)

## 7. Access Control Policies
Políticas de controlo de acesso definem quem pode aceder a que recursos e em que condições. As políticas podem ser baseadas em papéis (RBAC), atributos (ABAC) ou listas de controlo de acesso (ACL).

### 7.1 Role-Based Access Control (RBAC)
Um modelo de controlo de acesso baseado em papéis, onde os utilizadores são atribuídos a papéis e os papéis têm permissões associadas. As permissões são concedidas com base no papel do utilizador, permitindo uma gestão mais eficiente dos direitos de acesso.
### 7.2 Discretionary Access Control (DAC)
Um modelo de controlo de acesso onde o proprietário do recurso decide quem pode aceder ao recurso e em que condições. O proprietário pode conceder ou revogar permissões a outros utilizadores.

### 7.3 Mandatory Access Control (MAC)
Um modelo de controlo de acesso onde o sistema define as regras de acesso e os utilizadores não podem alterar essas regras. As permissões são baseadas em etiquetas de segurança associadas aos recursos e aos utilizadores, garantindo que apenas utilizadores autorizados podem aceder a recursos sensíveis.

## 8. Cryptographic tokens

## 10. Digital signatures
Onde uma chave privada é usada para assinar um documento, e a chave pública é usada para verificar a assinatura. As assinaturas digitais garantem a autenticidade, integridade e não-repúdio do documento.

## 11. Octais
- 000
  - Forma simbólica: ----------
  - Significado: Nenhuma permissão para ninguém. O proprietário, o grupo e outros usuários não podem ler, escrever ou executar o arquivo.

- 100
  - Forma simbólica: ---x------
  - Significado: Apenas o proprietário tem permissão de execução. Ninguém pode ler ou escrever o arquivo, e o grupo e outros não têm permissões.
- 200
  - Forma simbólica: --w-------
  - SSignificado: Apenas o proprietário tem permissão de escrita. Ninguém pode ler ou executar o arquivo, e o grupo e outros não têm permissões.

- 400
  - Forma simbólica: --r-------
  - Significado: Apenas o proprietário tem permissão de leitura. Ninguém pode escrever ou executar o arquivo, e o grupo e outros não têm permissões.

- 644
  - Forma simbólica: -rw-r--r--
  - Significado: O proprietário tem permissão de leitura e escrita (4 + 2 = 6), enquanto o grupo e outros têm apenas permissão de leitura (4). Comum em arquivos de texto ou configuração.

- 755
  - Forma simbólica: -rwxr-xr-x
  - SSignificado: O proprietário tem todas as permissões: leitura, escrita e execução (4 + 2 + 1 = 7). O grupo e outros têm permissão de leitura e execução (4 + 1 = 5). Usado frequentemente em scripts ou programas executáveis.

- 777
  - Forma simbólica: -rwxrwxrwx
  - Significado: Todos (proprietário, grupo e outros) têm permissão total: leitura, escrita e execução (4 + 2 + 1 = 7). Raramente usado por questões de segurança.
