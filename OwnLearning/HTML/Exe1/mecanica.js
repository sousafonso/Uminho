const form = document.querySelector('form');
const nome = form.elements.nome;
const email = form.elements.email;
const mensagem = form.elements.mensagem;

form.addEventListener('submit', function(e) {
  e.preventDefault();
  let valido = true;

  if (nome.value.length < 3 || !/^[a-zA-Z\s]+$/.test(nome.value)) {
    showError(nome, 'Nome inválido');
    valido = false;
  } else clearError(nome);

  if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(email.value)) {
    showError(email, 'Email inválido');
    valido = false;
  } else clearError(email);

  if (mensagem.value.length < 10) {
    showError(mensagem, 'Mensagem muito curta');
    valido = false;
  } else clearError(mensagem);

  if (valido) form.submit();
});

function showError(input, msg) {
  let erro = input.nextElementSibling;
  if (!erro || !erro.classList.contains('erro')) {
    erro = document.createElement('span');
    erro.className = 'erro';
    input.after(erro);
  }
  erro.textContent = msg;
}
function clearError(input) {
  const erro = input.nextElementSibling;
  if (erro && erro.classList.contains('erro')) erro.remove();
}

// Tema claro/escuro
const toggleButton = document.getElementById('toggleTheme');
toggleButton.addEventListener('click', () => {
  document.body.classList.toggle('dark-mode');
});