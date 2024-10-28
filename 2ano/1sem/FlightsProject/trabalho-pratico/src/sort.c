#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../include/sort.h"
#include "../include/reservations.h"
#include "../include/flights.h"
#include "../include/users.h"
#include "../include/time.h"
#include "../include/statistics.h"

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
static void merge_reservations(Reservations **reservations, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    // Create temp arrays 
    Reservations *L[n1]; 
    Reservations *R[n2]; 

    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = reservations[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = reservations[m + 1 + j]; 

    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 

    // Initial index of second subarray 
    j = 0; 

    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        
        Reservations *left = L[i];
        Reservations *right = R[j];
            
        char *leftBeginDay = get_begin_date(left);
        char *rightBeginDay = get_begin_date(right);
        char *leftId = get_reservation_id(left);
        char *rightId = get_reservation_id(right);

        if (days_time_all(leftBeginDay, rightBeginDay) > 0 || (days_time_all(leftBeginDay, rightBeginDay) == 0 && compara_reservation_id(leftId, rightId) > 0)) { 
            reservations[k] = R[j]; 
            j++; 
        } 
        else { 
            reservations[k] = L[i]; 
            i++; 
        } 
        k++; 

        free(leftBeginDay);
        leftBeginDay = NULL;
        free(rightBeginDay);
        rightBeginDay = NULL;
        free(rightId);
        rightId = NULL;
        free(leftId);
        leftId = NULL;
    } 

    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        reservations[k] = L[i]; 
        i++; 
        k++; 
    } 

    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        reservations[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void reservation_sort(Reservations **reservations, int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        reservation_sort(reservations, l, m); 
        reservation_sort(reservations, m + 1, r); 

        merge_reservations(reservations, l, m, r); 
    } 
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
static void merge_flights(Flights **flights, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    // Create temp arrays 
    Flights *L[n1]; 
    Flights *R[n2]; 

    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = flights[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = flights[m + 1 + j]; 

    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 

    // Initial index of second subarray 
    j = 0; 

    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        
        Flights *left = L[i];
        Flights *right = R[j];
            
        char *currentDepDay = get_dep(left);
        char *currentId = get_flight_id(left);
        char *nextDepDay = get_dep(right);
        char *nextId = get_flight_id(right);

        if (seconds_time_all(currentDepDay, nextDepDay) > 0 || (seconds_time_all(currentDepDay, nextDepDay) == 0 && (atoi(nextId) < atoi(currentId)))) { 
            flights[k] = R[j]; 
            j++; 
        } 
        else { 
            flights[k] = L[i]; 
            i++; 
        } 
        k++; 

        free(currentDepDay);
        currentDepDay = NULL;
        free(currentId);
        currentId = NULL;
        free(nextDepDay);
        nextDepDay = NULL;
        free(nextId);
        nextId = NULL;
    } 

    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        flights[k] = L[i]; 
        i++; 
        k++; 
    } 

    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        flights[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void flight_sort(Flights **flights, int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        flight_sort(flights, l, m); 
        flight_sort(flights, m + 1, r); 

        merge_flights(flights, l, m, r); 
    } 
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
static void merge_arrays(char *airplanes, int *total_passengers, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    // Create temp arrays 
    int L[n1]; 
    int R[n2];
    char LL[n1 * 3];
    char RR[n2 * 3]; 

    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++){ 
        L[i] = total_passengers[l + i]; 
        LL[3*i] = airplanes[3*l + 3*i];
        LL[3*i + 1] = airplanes[3*l + 3*i + 1];
        LL[3*i + 2] = airplanes[3*l + 3*i + 2];
    }
    for (j = 0; j < n2; j++){
        R[j] = total_passengers[m + 1 + j]; 
        RR[3*j] = airplanes[3*m + 3 + 3*j];
        RR[3*j + 1] = airplanes[3*m + 3 + 3*j + 1];
        RR[3*j + 2] = airplanes[3*m + 3 + 3*j + 2];
    }

    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 

    // Initial index of second subarray 
    j = 0; 

    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        char *airplane = get_current_airport(LL + 3*i);
        char *sec_airplane = get_current_airport(RR + 3*j);

        if (R[j] > L[i] || (R[j] == L[i] && strcmp(airplane, sec_airplane) > 0)) { 
            total_passengers[k] = R[j];
            airplanes[3*k] = RR[j*3];
            airplanes[3*k + 1] = RR[j*3 + 1];
            airplanes[3*k + 2] = RR[j*3 + 2];
            j++; 
        } 
        else { 
            total_passengers[k] = L[i]; 
            airplanes[3*k] = LL[i*3];
            airplanes[3*k + 1] = LL[i*3 + 1];
            airplanes[3*k + 2] = LL[i*3 + 2];
            i++; 
        } 
        free(sec_airplane);
        sec_airplane = NULL;
        free(airplane);
        airplane = NULL;
        k++; 
    } 

    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        total_passengers[k] = L[i]; 
        airplanes[3*k] = LL[i*3];
        airplanes[3*k + 1] = LL[i*3 + 1];
        airplanes[3*k + 2] = LL[i*3 + 2];
        i++; 
        k++; 
    } 

    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        total_passengers[k] = R[j]; 
        airplanes[3*k] = RR[j*3];
        airplanes[3*k + 1] = RR[j*3 + 1];
        airplanes[3*k + 2] = RR[j*3 + 2];
        j++; 
        k++; 
    } 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void sort_arrays(char *airplanes, int *total_passengers, int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        sort_arrays(airplanes, total_passengers, l, m); 
        sort_arrays(airplanes, total_passengers, m + 1, r); 

        merge_arrays(airplanes, total_passengers, l, m, r); 
    } 
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
static void merge_array(int *quantos_atrasos, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    // Create temp arrays 
    int L[n1]; 
    int R[n2];

    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++)
        L[i] = quantos_atrasos[l + i]; 
    
    for (j = 0; j < n2; j++)
        R[j] = quantos_atrasos[m + 1 + j]; 

    

    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 

    // Initial index of second subarray 
    j = 0; 

    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 

        if (R[j] < L[i]) { 
            quantos_atrasos[k] = R[j];
            j++; 
        } 
        else { 
            quantos_atrasos[k] = L[i]; 
            i++; 
        } 
        k++; 
    } 

    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        quantos_atrasos[k] = L[i]; 
        i++; 
        k++; 
    } 

    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        quantos_atrasos[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void sort_int_array(int *quantos_atrasos, int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        sort_int_array(quantos_atrasos, l, m); 
        sort_int_array(quantos_atrasos, m + 1, r); 

        merge_array(quantos_atrasos, l, m, r); 
    } 
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
static void merge_arrays_double(char *airplanes, double *medianas, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    // Create temp arrays 
    double L[n1]; 
    double R[n2];
    char LL[n1 * 3];
    char RR[n2 * 3]; 

    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++){ 
        L[i] = medianas[l + i]; 
        LL[3*i] = airplanes[3*l + 3*i];
        LL[3*i + 1] = airplanes[3*l + 3*i + 1];
        LL[3*i + 2] = airplanes[3*l + 3*i + 2];
    }
    for (j = 0; j < n2; j++){
        R[j] = medianas[m + 1 + j]; 
        RR[3*j] = airplanes[3*m + 3 + 3*j];
        RR[3*j + 1] = airplanes[3*m + 3 + 3*j + 1];
        RR[3*j + 2] = airplanes[3*m + 3 + 3*j + 2];
    }

    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 

    // Initial index of second subarray 
    j = 0; 

    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        char *airplane = get_current_airport(LL + 3*i);
        char *sec_airplane = get_current_airport(RR + 3*j);

        if (R[j] > L[i] || (R[j] == L[i] && strcmp(airplane, sec_airplane) > 0)) { 
            medianas[k] = R[j];
            airplanes[3*k] = RR[j*3];
            airplanes[3*k + 1] = RR[j*3 + 1];
            airplanes[3*k + 2] = RR[j*3 + 2];
            j++; 
        } 
        else { 
            medianas[k] = L[i]; 
            airplanes[3*k] = LL[i*3];
            airplanes[3*k + 1] = LL[i*3 + 1];
            airplanes[3*k + 2] = LL[i*3 + 2];
            i++; 
        } 
        free(sec_airplane);
        sec_airplane = NULL;
        free(airplane);
        airplane = NULL;
        k++; 
    } 

    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        medianas[k] = L[i]; 
        airplanes[3*k] = LL[i*3];
        airplanes[3*k + 1] = LL[i*3 + 1];
        airplanes[3*k + 2] = LL[i*3 + 2];
        i++; 
        k++; 
    } 

    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        medianas[k] = R[j]; 
        airplanes[3*k] = RR[j*3];
        airplanes[3*k + 1] = RR[j*3 + 1];
        airplanes[3*k + 2] = RR[j*3 + 2];
        j++; 
        k++; 
    } 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void sort_arrays_double(char *airplanes, double *medianas, int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        sort_arrays_double(airplanes, medianas, l, m); 
        sort_arrays_double(airplanes, medianas, m + 1, r); 

        merge_arrays_double(airplanes, medianas, l, m, r); 
    } 
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
static void merge_users(Users **users, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    // Create temp arrays 
    Users *L[n1]; 
    Users *R[n2]; 

    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = users[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = users[m + 1 + j]; 

    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 

    // Initial index of second subarray 
    j = 0; 

    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        
        Users *current = L[i];
        Users *next = R[j];
            
        char *currentName = get_user_name(current);
        char *nextName = get_user_name(next);
        char *currentId = get_user_id(current);
        char *nextId = get_user_id(next);
        
        if (strcoll(currentName, nextName) > 0 || (strcoll(currentName, nextName) == 0 && strcoll(currentId, nextId) > 0)) {
            users[k] = R[j]; 
            j++; 
        } 
        else { 
            users[k] = L[i]; 
            i++; 
        } 
        free(currentName);
        currentName = NULL;
        free(nextName);
        nextName = NULL;
        free(nextId);
        nextId = NULL;
        free(currentId);
        currentId = NULL;
        k++; 
    } 

    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        users[k] = L[i]; 
        i++; 
        k++; 
    } 

    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        users[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void user_sort(Users **users, int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        user_sort(users, l, m); 
        user_sort(users, m + 1, r); 

        merge_users(users, l, m, r); 
    } 
}

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
static void merge_ID_users(Users **users, int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    // Create temp arrays 
    Users *L[n1]; 
    Users *R[n2]; 

    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = users[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = users[m + 1 + j]; 

    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 

    // Initial index of second subarray 
    j = 0; 

    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        
        Users *current = L[i];
        Users *next = R[j];
    
        char *currentId = get_user_id(current);
        char *nextId = get_user_id(next);
        
        if (strcoll(currentId, nextId) > 0) {
            users[k] = R[j]; 
            j++; 
        } 
        else { 
            users[k] = L[i]; 
            i++; 
        } 
        free(nextId);
        nextId = NULL;
        free(currentId);
        currentId = NULL;
        k++; 
    } 

    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        users[k] = L[i]; 
        i++; 
        k++; 
    } 

    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        users[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void user_ID_sort(Users **users, int l, int r){ 
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and r 
        int m = l + (r - l) / 2; 

        // Sort first and second halves 
        user_ID_sort(users, l, m); 
        user_ID_sort(users, m + 1, r); 

        merge_ID_users(users, l, m, r); 
    } 
}