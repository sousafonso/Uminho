# TEORIA

---
## Terminologia
- **Plaintext**: mensagem original
- **Encryption***: processo de transformar a mensagem original numa mensagem cifrada (ciphertext)
- **Decryption**: processo de transformar a mensagem cifrada na mensagem original
- **Sistema Criptográfico**: sistema que implementa algoritmos de cifragem e decifragem
- **Ataque**: tentativa de obter a mensagem original a partir da mensagem cifrada

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
### 3.1 Stream Ciphers
Basicamente um XOR entre a mensagem e uma chave. A chave é gerada a partir de um algoritmo que gera uma sequência de bits pseudo-aleatória. O algoritmo é conhecido, mas a chave é secreta.


---
## 4. Certificados

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


Os certificados sao sempre utilizados aquando da partilha da chave publica. A chave publica é sempre acompanhada de um certificado.
Cerficados sem CA são auto-assinados (self-signed). A chave publica é assinada pela própria entidade que a possui. Este tipo de certificado não é confiável, pois não existe uma terceira parte que o valide. Issuer = subject.

**Validação**
Para cada certificado, o cliente tem de verificar:
- Assinatura: verificar se a assinatura do certificado é válida (assinar com a chave publica da CA);
- A aplicação do certificado: verificar se o certificado é aplicável à chave publica (verificar se o subject corresponde ao nome do servidor);

**Trust Anchors**
O utilizador sabe um numero limitado de chaves publicas que pertençam a entidades de confiança (CA) que atuam como as raízes de confiança.
Normalmente é o sistema operativo que gere a lista de CA de confiança. A compilação e atualização é feita pelo SO.

### 4.1 Certificados standard
A utilização de certificados de chave publica necessitam de uma fundamentação sólida estabelecida e sistematizada:
- Formatos
- Convenções e assumptions
- Prática e processos

## 5. Public-key infrastructure (PKI)
### 5.1 Infraestrutura de chave pública (PKI)
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

## 6. Communication protocols (TLS)

## 7. Document signing

## 8. Cryptographic tokens