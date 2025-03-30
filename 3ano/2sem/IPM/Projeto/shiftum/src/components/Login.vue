<template>
    <!-- <h2 class="login-title">Login</h2> -->
    <div class="login-container">
      <form @submit.prevent="login">
        <!-- Campo E-mail -->
        <div class="input-group">
          <label for="email">E-mail address</label>
          <input
            type="email"
            id="email"
            v-model="email"
            placeholder="E-mail address"
            required
          />
        </div>
  
        <!-- Campo Password com ícone para exibir/ocultar -->
        <div class="input-group">
          <label for="password">Password</label>
          <div class="password-wrapper">
            <input
              :type="showPassword ? 'text' : 'password'"
              id="password"
              v-model="password"
              placeholder="Password"
              required
            />
            <span class="toggle-password" @click="togglePassword">
              <!-- Ícone simples. Substitua por algo mais estilizado (SVG, Font Awesome etc.) -->
              {{ showPassword ? '🙈' : '👁️' }}
            </span>
          </div>
        </div>
  
        <!-- Botão de Login -->
        <button type="submit">Login</button>
      </form>
    </div>
  </template>
  
  <script>
  export default {
    name: 'LoginForm',
    data() {
      return {
        email: '',
        password: '',
        showPassword: false
      };
    },
    methods: {
      login() {
        // Lógica de autenticação
        console.log('E-mail:', this.email, 'Password:', this.password);
      },
      togglePassword() {
        this.showPassword = !this.showPassword;
      }
    }
  };
  </script>
  
  <style scoped>
  /* Container do bloco de login (fundo cinza, bordas arredondadas etc.) */
  .login-container {
    background-color: #959595; /* Ajuste conforme a cor desejada para o "card" */
    padding: 2rem;
    border-radius: 8px;
    width: 350px;
    box-shadow: 0 0 10px rgba(0,0,0,0.3);
    display: flex;
    flex-direction: column;
  }
  
  /* Título "Login" */
  .login-title {
    position: relative;
    top: -2rem;
    text-align: center;
    margin-bottom: 1rem;
    font-size: 1.5rem;
    color: #fff;
  }
  
  /* Espaçamento entre grupos de input */
  .input-group {
    margin-bottom: 1rem;
    display: flex;
    flex-direction: column;
  }
  
  /* Label */
  .input-group label {
    margin-bottom: 0.5rem;
    color: #fff;
  }
  
  /* Ajustes do campo de senha para comportar ícone "olho" */
  .password-wrapper {
    position: relative;
  }
  
  /* Ícone de alternar senha (olho) */
  .toggle-password {
    position: absolute;
    right: 0.5rem;
    top: 50%;
    transform: translateY(-50%);
    cursor: pointer;
  }
  
  /* Inputs gerais */
  .input-group input {
    padding: 0.5rem;
    border: 1px solid #ccc;
    border-radius: 4px;
  }
  
  /* Botão de Login */
  button[type="submit"] {
    padding: 0.75rem;
    border: none;
    border-radius: 4px;
    background-color: #fff;
    color: #333;
    cursor: pointer;
    font-size: 1rem;
    font-weight: bold;
    margin-top: 0.5rem;
  }
  
  button[type="submit"]:hover {
    background-color: #ddd;
  }
  </style>
  