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
        // Lógica de autenticação simulada via JSON Server
        fetch('http://localhost:3000/users')
          .then(response => response.json())
          .then(users => {
            const user = users.find(u => u.email === this.email && u.password === this.password);
            if (user) {
              console.log('Usuário autenticado:', user);
              if (user.role === 'student') {
                // Direciona aluno para o menu do aluno
                this.$router.push('../Aluno/Menu.vue');
              } else if (user.role === 'director') {
                // Direciona diretor para o menu inicial
                this.$router.push('../Diretor/Menu.vue');
              }
            } else {
              console.error('Credenciais inválidas');
            }
          })
          .catch(error => {
            console.error('Erro na autenticação:', error);
          });
      },
      togglePassword() {
        this.showPassword = !this.showPassword;
      }
    }
  };