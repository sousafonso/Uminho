import Vue from 'vue';
import Router from 'vue-router';
import Login from '@/components/Login.vue';

const AlunoMenu = () => import('@/components/Aluno/Menu.vue');
const DiretorMenu = () => import('@/components/Diretor/Menu.vue');

Vue.use(Router);

export default new Router({
  mode: 'history',
  routes: [
    {
      path: '/',
      name: 'Login',
      component: Login
    },
    {
      path: '/Aluno/Menu',
      name: 'AlunoMenu',
      component: AlunoMenu
    },
    {
      path: '/Diretor/Menu',
      name: 'DiretorMenu',
      component: DiretorMenu
    }
  ]
});