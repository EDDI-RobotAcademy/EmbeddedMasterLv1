<template>
  <div class="app">
    <router-link style="text-decoration: none;" :to="{ name: 'Home' }">
        &nbsp;Home&nbsp;
    </router-link>
    <router-link style="text-decoration: none;" :to="{ name: 'VuetifyMemberRegisterPage' }">
      &nbsp;Vuetify Member Register Test&nbsp;
    </router-link>

    <router-link style="text-decoration: none;" :to="{ name: 'LoginTestPage' }">
      &nbsp;Login Test&nbsp;
    </router-link>
    <router-link style="text-decoration: none;" :to="{ name: 'JpaBoardListPage' }">
      &nbsp;Jpa Board List&nbsp;
    </router-link>

    <router-link style="text-decoration: none;" :to="{ name: 'VuetifyMemberJoinColumnTestPage' }">
      &nbsp;VuetifyMemberJoinColumnTest&nbsp;
    </router-link>
    <br/>
  </div>
</template>

<script>
// @ is an alias to /src
//import HelloWorld from '@/components/HelloWorld.vue'

export default {
  name: 'Home',
  components: {
  }
}
</script>