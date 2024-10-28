#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/UserNode.h"
#include "../include/users.h"

typedef struct usernode{
    Users **user;
    int max_users;
    int key;
    int howOccupied; //quantos users tem neste nodo
} UserNode;

Users **get_first_user(const UserNode *userNode){
    if(userNode == NULL) return NULL;
    if(userNode->user) return userNode->user;
    return NULL;
}

int get_last_user(const UserNode *userNode){
    if(userNode == NULL) return 0;
    return userNode->max_users;
}

int get_user_node_occupied(const UserNode *userNode){
    if(userNode->howOccupied) return userNode->howOccupied;
    return 0;
}

int get_user_node_key(const UserNode *userNode){
    if(userNode->key) return userNode->key;
    return -1;
}

void set_first_user(UserNode *userNode, Users **user){
    if(userNode) userNode->user = user;
}

void set_one_user(UserNode *userNode, Users *user){
    if(userNode) userNode->user[userNode->howOccupied] = user;
}

void set_last_user(UserNode *userNode, int last_user){
    if(userNode) userNode->max_users = last_user;
}

void set_user_node_occupied(UserNode *userNode, int occupied){
    if(userNode) userNode->howOccupied = occupied;
}

void set_user_node_key(UserNode *userNode, int key){
    if(userNode) userNode->key = key;
}

UserNode *create_user_node(void){
    UserNode *userNode = (UserNode*)malloc(sizeof(UserNode));
    if(!userNode) {
        perror("Erro ao alocar memória para a tabela de users");
        exit(EXIT_FAILURE);
    }
    userNode->key = -1;
    userNode->howOccupied = 0;
    userNode->max_users = 512;
    userNode->user = malloc(sizeof(Users *) * 512);
    if (!userNode->user) {
        perror("Erro ao alocar memória para o node de users");
        free(userNode);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 512; i++) userNode->user[i] = NULL;
    return userNode;
}

void free_user_node(UserNode *userNode){
    if(userNode == NULL) return;
    int size = userNode->howOccupied;
    for(int i = 0; i < size; i++) free_user(userNode->user[i]);
    free(userNode->user);
    free(userNode);
}

int find_key(int key, UserNode **users, int used_users){
    if(used_users == 0) return -1;
    int middle = used_users/2;
    int user_key = users[middle]->key;
    if(user_key == key) return middle;
    if(user_key > key) return find_key(key, users, middle);
    else return middle + 1 + find_key(key, users + middle + 1, used_users - middle - 1);
}