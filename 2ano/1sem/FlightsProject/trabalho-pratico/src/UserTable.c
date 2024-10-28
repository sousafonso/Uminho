#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/UserTable.h"
#include "../include/UserNode.h"
#include "../include/users.h"
#include "../include/sort.h"

typedef struct userstable {
    UserNode **users;
    int used_users;
    int userSize;
} UsersTable;

UserNode *get_user_node(const UsersTable *userTable, int node){
    if(userTable == NULL) return NULL;
    if(userTable->users[node]) return userTable->users[node];
    return NULL;
}

int get_user_table_size(const UsersTable *userTable){
    if(userTable->userSize) return userTable->userSize;
    return 0;
}

int get_user_table_occupied(const UsersTable *userTable){
    if(userTable) return userTable->used_users;
    return 0;
}

//função que cria a userTable
UsersTable *create_user_table(void){
    UsersTable *userTable = (UsersTable*)malloc(sizeof(UsersTable));
    if(!userTable) {
        perror("Erro ao alocar memória para a tabela de users");
        exit(EXIT_FAILURE);
    }
    userTable->used_users = 0;
    userTable->userSize = 512;
    userTable->users = malloc(sizeof(UserNode *) * 512);
    if (!userTable->users) {
        perror("Erro ao alocar memória para a tabela de users");
        free(userTable);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 512; i++) userTable->users[i] = NULL;
    return userTable;
}

//insere um novo user
void insert_user(char *user_id, Users *newUser, UsersTable *userTable) {
    int total_users = hash_user(user_id);  
    int last_users = userTable->used_users;
    if(last_users >= userTable->userSize){
        userTable->userSize += last_users;
        userTable->users = realloc(userTable->users,sizeof(UserNode *) * userTable->userSize);
        for(int i = last_users; i < userTable->userSize; i++) userTable->users[i] = NULL;
    }

    int user_key = find_key(total_users, userTable->users, last_users);
    if(user_key == -1 || total_users != get_user_node_key(userTable->users[user_key])) {
        int i = last_users;
        for(; i > 0 && get_user_node_key(userTable->users[i - 1]) > total_users; i--){
            userTable->users[i] = userTable->users[i - 1];
            /*set_user_node_occupied(userTable->users[i], get_user_node_occupied(userTable->users[i - 1]));
            set_user_node_key(userTable->users[i], get_user_node_key(userTable->users[i - 1]));
            set_first_user(userTable->users[i], get_first_user(userTable->users[i - 1]));
            set_last_user(userTable->users[i], get_last_user(userTable->users[i - 1]));*/
        }
        userTable->users[i] = create_user_node();
        UserNode *currentUser = userTable->users[i];
        set_user_node_key(currentUser, total_users);
        set_one_user(currentUser, newUser);
        set_user_node_occupied(currentUser, 1);
        userTable->used_users++;  
    }

    else{
        UserNode *currentUser = userTable->users[user_key];
        Users **user = get_first_user(currentUser);

        int max_user = get_last_user(currentUser);
        int current = get_user_node_occupied(currentUser);

        if(current >= max_user){
            set_last_user(currentUser, max_user + current);
            user = realloc(user,sizeof(Users *) * (max_user + current));
            for(int i = current; i < max_user + current; i++) user[i] = NULL;
            set_first_user(currentUser, user);
        }
        set_one_user(currentUser, newUser);
        set_user_node_occupied(currentUser, current + 1);
    }
}

static Users *the_user(char *user_id, Users **users, int used_users){//menor para maior
    if(used_users == 0) return NULL;
    int middle = used_users/2;
    char *currentUserId = get_user_id(users[middle]);
    if(strcoll(currentUserId, user_id) == 0) {
        free(currentUserId);
        currentUserId = NULL;
        return users[middle];
    }
    if(strcoll(currentUserId, user_id) > 0) {
        free(currentUserId);
        currentUserId = NULL;
        return the_user(user_id, users, middle);
    }
    else {
        free(currentUserId);
        currentUserId = NULL;
        return the_user(user_id, users + middle + 1, used_users - middle - 1);
    }
}

//procura um user
Users *find_user(char* user_id, UsersTable *userTable) {
    int keyValue = hash_user(user_id);
    int user_key = find_key(keyValue, userTable->users, userTable->used_users);

    if(user_key != -1 && keyValue == get_user_node_key(userTable->users[user_key])){
        Users **current = get_first_user(userTable->users[user_key]);
        Users *me = the_user(user_id, current, get_user_node_occupied(userTable->users[user_key]));
        if(me) return me;
    }
    return NULL;  // User não encontrado
}

void sort_users_table(UsersTable *usersTable){
    int size = usersTable->used_users;
    for(int i = 0; i < size; i++){
        UserNode *currentUser = usersTable->users[i];
        Users **user = get_first_user(currentUser);
        int max = get_user_node_occupied(currentUser) - 1;
        user_ID_sort(user, 0, max);
    }
}

//free na user table
void free_user_table(UsersTable *userTable){
    int total_users = userTable->userSize;
    for (int i = 0; i < total_users; i++) {
        UserNode* current_user = userTable->users[i];
        free_user_node(current_user);
    }
    free(userTable->users);
    free(userTable);
}
