
#include<stdio.h>

struct Train {
    int trainNumber;
    char trainName[50];
    char start[50];
    char destination[50];
};

struct Ticket {
    int ticketId;
    char passengerName[50];
    int trainNumber;
    int seatNumber;
};

struct Train trains[3] = {
    {101, "Express", "CityA", "CityB"},
    {102, "SuperFast", "CityC", "CityD"},
    {103, "Local", "CityE", "CityF"}
};

struct Ticket tickets[100];
int ticketCounter = 0;

void viewTrains() {
    printf("\nAvailable Trains:\n");
    for(int i = 0; i < 3; i++) {
        printf("Train Number: %d, Train Name: %s, Start: %s, Destination: %s\n", 
               trains[i].trainNumber, trains[i].trainName, trains[i].start, trains[i].destination);
    }
}

void bookTicket() {
    struct Ticket ticket;
    printf("\nEnter passenger name: ");
    scanf("%s", ticket.passengerName);
    printf("Enter train number: ");
    scanf("%d", &ticket.trainNumber);
    ticket.ticketId = ticketCounter + 1;
    ticket.seatNumber = ticketCounter + 1;  
    tickets[ticketCounter++] = ticket;
    printf("\nTicket Booked Successfully! Ticket ID: %d, Seat Number: %d\n", ticket.ticketId, ticket.seatNumber);
}

void cancelTicket() {
    int ticketId;
    printf("\nEnter ticket ID to cancel: ");
    scanf("%d", &ticketId);

    for(int i = 0; i < ticketCounter; i++) {
        if(tickets[i].ticketId == ticketId) {
            for(int j = i; j < ticketCounter - 1; j++) {
                tickets[j] = tickets[j + 1]; 
            }
            ticketCounter--;
            printf("Ticket Cancelled Successfully!\n");
            return;
        }
    }
    printf("Ticket ID not found!\n");
}

void viewBookings() {
    printf("\nAll Bookings:\n");
    for(int i = 0; i < ticketCounter; i++) {
        printf("Ticket ID: %d, Passenger Name: %s, Train Number: %d, Seat Number: %d\n", 
               tickets[i].ticketId, tickets[i].passengerName, tickets[i].trainNumber, tickets[i].seatNumber);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n--- Railway Reservation System ---\n");
        printf("1. View Trains\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. View Bookings\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                viewTrains();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                viewBookings();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}