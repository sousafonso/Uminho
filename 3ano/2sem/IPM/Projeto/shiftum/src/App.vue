<template>
  <div class="app-container">
    <!-- Seção da Esquerda (Logo + Texto) -->
    <div class="left-section">
      <!-- Ajuste a URL ou use um <img> para a logo -->
      <div class="logo">
      </div>
      <p class="shiftum">ShiftUM</p>
    </div>

    <!-- Seção da Direita (Formulário de Login) -->
    <div class="right-section">
      <Login />
    </div>
  </div>
</template>

<script>
import Login from './components/Login.vue'; 

export default {
  name: 'App',
  components: {
    Login
  }
};
</script>

<style>
/* Faz com que a aplicação ocupe toda a tela do navegador */
html, body, #app {
  margin: 0;
  padding: 0;
  height: 100%;
}

/* Container principal dividindo a tela em duas partes */
.app-container {
  display: flex;
  background-color: #2C3E50; /* Fundo escuro semelhante à imagem */
  height: 100vh;
}

/* Seção da esquerda (logo + texto) */
.left-section {
  flex: 1;
  display: flex;
  flex-direction: column;
  justify-content: center; /* Alinha verticalmente no centro */
  align-items: center;     /* Alinha horizontalmente no centro */
}

/* Logo - você pode substituir por <img> ou background */
.logo {
  width: 600px; /* Ajuste o tamanho conforme necessário */
  height: 600px; /* Ajuste o tamanho conforme necessário */
  background: url('./assets/logo.png') no-repeat center; /* Ajuste a URL */
  background-size: contain;
}

/* Texto "ShiftUM" */
.shiftum {
  font-size: 6rem;
  color: #ffffff;
  font-family: "Kode Mono"; /* Para lembrar o estilo "digitado" */
  margin-top: 1px;
}

/* Seção da direita (login) */
.right-section {
  flex: 1;
  display: flex;
  justify-content: center; /* Centraliza horizontalmente o form */
  align-items: center;     /* Centraliza verticalmente o form */
}
</style>
