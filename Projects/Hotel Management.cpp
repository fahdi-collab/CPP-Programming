#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Menu choice
    int menuChoice = 0;
    
    // Booking Details
    bool hasActiveBooking = false;
    string guestName = "";
    string guestPhone = "";
    int roomType = 0;             // 1: Standard, 2: Deluxe, 3: Executive Suite
    string roomName = "";
    double roomRate = 0.0;
    int stayDays = 0;
    int numGuests = 0;
    
    // Additional amenities
    int breakfastOrders = 0;
    int dinnerOrders = 0;
    int laundryItems = 0;
    bool shuttleService = false;
    
    // Bill calculation variables
    double roomSubtotal = 0.0;
    double amenitiesTotal = 0.0;
    double discountRate = 0.0;
    double discountAmount = 0.0;
    double taxAmount = 0.0;
    double grandTotal = 0.0;
    
    // Hotel statistics
    int totalBookingsCount = 0;
    double totalRevenueCollected = 0.0;

    // Room and service rates
    const double RATE_STANDARD = 3500.00;
    const double RATE_DELUXE   = 6000.00;
    const double RATE_SUITE    = 10000.00;
    
    const double PRICE_BREAKFAST = 450.00;
    const double PRICE_DINNER    = 850.00;
    const double PRICE_LAUNDRY   = 150.00;
    const double PRICE_SHUTTLE   = 1200.00;
    const double GST_TAX_RATE    = 0.13; // 13% GST

    // Main application loop
    do {
        cout << "\n========================================================\n";
        cout << "           GRAND HORIZON HOTEL & RESIDENCY              \n";
        cout << "               Hotel Management System                  \n";
        cout << "========================================================\n";
        cout << "  1. View Room Categories & Daily Tariffs               \n";
        cout << "  2. Guest Check-In & Room Reservation                  \n";
        cout << "  3. Order Additional Amenities & Room Service          \n";
        cout << "  4. View Current Reservation & Estimated Bill          \n";
        cout << "  5. Guest Check-Out & Final Invoice Settlement         \n";
        cout << "  6. View Hotel Session Statistics                      \n";
        cout << "  7. Exit System                                        \n";
        cout << "========================================================\n";
        cout << "Enter your choice (1-7): ";
        cin >> menuChoice;

        // Input validation if user enters letters or invalid number
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[ERROR] Invalid input! Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (menuChoice) {
            
            // 1. Room categories and tariffs
            case 1: {
                cout << "\n--------------------------------------------------------\n";
                cout << "            ROOM CATEGORIES & TARIFF SCHEDULE           \n";
                cout << "--------------------------------------------------------\n";
                cout << left << setw(8) << "Type" 
                     << setw(20) << "Category" 
                     << setw(16) << "Rate / Night" 
                     << "Amenities Included\n";
                cout << "--------------------------------------------------------\n";
                cout << left << setw(8) << "1" 
                     << setw(20) << "Standard Room" 
                     << setw(16) << "PKR 3,500.00" 
                     << "Single Bed, AC, Free Wi-Fi\n";
                cout << left << setw(8) << "2" 
                     << setw(20) << "Deluxe Room" 
                     << setw(16) << "PKR 6,000.00" 
                     << "King Bed, Smart TV, Mini Bar\n";
                cout << left << setw(8) << "3" 
                     << setw(20) << "Executive Suite" 
                     << setw(16) << "PKR 10,000.00" 
                     << "Master Suite, Balcony, Jacuzzi\n";
                cout << "--------------------------------------------------------\n";
                cout << "Note: 13% Government Service Tax applicable at checkout.\n";
                cout << "Special Offer: 10% discount on stays exceeding 5 days!\n";
                cout << "--------------------------------------------------------\n";
                break;
            }

            // 2. Check-in guest
            case 2: {
                cout << "\n--------------------------------------------------------\n";
                cout << "               GUEST CHECK-IN & RESERVATION             \n";
                cout << "--------------------------------------------------------\n";

                if (hasActiveBooking) {
                    cout << "[ALERT] A guest (" << guestName << ") is currently checked in!\n";
                    cout << "Please complete check-out for the active booking first.\n";
                    break;
                }

                cin.ignore(1000, '\n'); // Clear stream buffer
                cout << "Enter Guest Full Name: ";
                getline(cin, guestName);

                cout << "Enter Guest Contact Number: ";
                getline(cin, guestPhone);

                // Room type selection and validation
                roomType = 0;
                while (roomType < 1 || roomType > 3) {
                    cout << "Select Room Type (1: Standard, 2: Deluxe, 3: Suite): ";
                    cin >> roomType;

                    if (roomType < 1 || roomType > 3) {
                        cout << "[ERROR] Invalid selection! Please choose between 1, 2, or 3.\n";
                    }
                }

                if (roomType == 1) {
                    roomName = "Standard Room";
                    roomRate = RATE_STANDARD;
                } else if (roomType == 2) {
                    roomName = "Deluxe Room";
                    roomRate = RATE_DELUXE;
                } else {
                    roomName = "Executive Suite";
                    roomRate = RATE_SUITE;
                }

                // Stay duration validation
                stayDays = 0;
                while (stayDays <= 0) {
                    cout << "Enter Number of Nights to Stay: ";
                    cin >> stayDays;
                    if (stayDays <= 0) {
                        cout << "[ERROR] Duration of stay must be at least 1 night!\n";
                    }
                }

                // Guest count validation
                numGuests = 0;
                while (numGuests <= 0 || numGuests > 5) {
                    cout << "Enter Number of Guests (1 - 5): ";
                    cin >> numGuests;
                    if (numGuests <= 0 || numGuests > 5) {
                        cout << "[ERROR] Number of guests must be between 1 and 5 per room!\n";
                    }
                }

                // Calculate room charges
                roomSubtotal = roomRate * stayDays;
                hasActiveBooking = true;
                
                // Reset services for this new booking
                breakfastOrders = 0;
                dinnerOrders = 0;
                laundryItems = 0;
                shuttleService = false;
                amenitiesTotal = 0.0;

                cout << "\n[SUCCESS] Check-In Successful!\n";
                cout << "Guest " << guestName << " assigned to " << roomName << ".\n";
                cout << "Room Charges for " << stayDays << " night(s): PKR " 
                     << fixed << setprecision(2) << roomSubtotal << "\n";
                break;
            }

            // 3. Additional amenities and services
            case 3: {
                cout << "\n--------------------------------------------------------\n";
                cout << "          ADDITIONAL AMENITIES & SERVICE ORDER          \n";
                cout << "--------------------------------------------------------\n";

                if (!hasActiveBooking) {
                    cout << "[ALERT] No active check-in found! Please book a room first.\n";
                    break;
                }

                int amenityChoice = 0;
                do {
                    cout << "\nActive Guest: " << guestName << " (" << roomName << ")\n";
                    cout << "1. Breakfast Buffet (PKR 450 per meal)\n";
                    cout << "2. Chef's Special Dinner (PKR 850 per meal)\n";
                    cout << "3. Laundry & Dry Cleaning (PKR 150 per garment)\n";
                    cout << "4. Airport Pick & Drop Shuttle (PKR 1,200 flat)\n";
                    cout << "5. Return to Main Menu\n";
                    cout << "Enter amenity choice (1-5): ";
                    cin >> amenityChoice;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "[ERROR] Invalid choice!\n";
                        continue;
                    }

                    switch (amenityChoice) {
                        case 1: {
                            int count = 0;
                            cout << "Enter number of breakfast meals to order: ";
                            cin >> count;
                            if (count > 0) {
                                breakfastOrders += count;
                                amenitiesTotal += (count * PRICE_BREAKFAST);
                                cout << "[CONFIRMED] " << count << " Breakfast meal(s) added.\n";
                            } else {
                                cout << "[NOTICE] Quantity must be positive.\n";
                            }
                            break;
                        }
                        case 2: {
                            int count = 0;
                            cout << "Enter number of dinner meals to order: ";
                            cin >> count;
                            if (count > 0) {
                                dinnerOrders += count;
                                amenitiesTotal += (count * PRICE_DINNER);
                                cout << "[CONFIRMED] " << count << " Dinner meal(s) added.\n";
                            } else {
                                cout << "[NOTICE] Quantity must be positive.\n";
                            }
                            break;
                        }
                        case 3: {
                            int count = 0;
                            cout << "Enter number of clothing items for laundry: ";
                            cin >> count;
                            if (count > 0) {
                                laundryItems += count;
                                amenitiesTotal += (count * PRICE_LAUNDRY);
                                cout << "[CONFIRMED] " << count << " Laundry item(s) logged.\n";
                            } else {
                                cout << "[NOTICE] Quantity must be positive.\n";
                            }
                            break;
                        }
                        case 4: {
                            if (!shuttleService) {
                                shuttleService = true;
                                amenitiesTotal += PRICE_SHUTTLE;
                                cout << "[CONFIRMED] Airport Shuttle Service scheduled.\n";
                            } else {
                                cout << "[NOTICE] Airport Shuttle is already scheduled for this stay.\n";
                            }
                            break;
                        }
                        case 5:
                            cout << "Returning to Main Menu...\n";
                            break;
                        default:
                            cout << "[ERROR] Invalid option! Please select 1-5.\n";
                    }

                } while (amenityChoice != 5);

                cout << "Updated Total Amenities Cost: PKR " 
                     << fixed << setprecision(2) << amenitiesTotal << "\n";
                break;
            }

            // 4. View current reservation summary
            case 4: {
                cout << "\n--------------------------------------------------------\n";
                cout << "             CURRENT RESERVATION DETAILS                \n";
                cout << "--------------------------------------------------------\n";

                if (!hasActiveBooking) {
                    cout << "[INFO] There is no active reservation currently in the system.\n";
                    break;
                }

                cout << left << setw(22) << "Guest Name:" << guestName << "\n";
                cout << left << setw(22) << "Contact Number:" << guestPhone << "\n";
                cout << left << setw(22) << "Assigned Room:" << roomName << "\n";
                cout << left << setw(22) << "Guests Count:" << numGuests << " Person(s)\n";
                cout << left << setw(22) << "Length of Stay:" << stayDays << " Night(s)\n";
                cout << left << setw(22) << "Daily Room Tariff:" << "PKR " << fixed << setprecision(2) << roomRate << "\n";
                cout << left << setw(22) << "Room Charges:" << "PKR " << fixed << setprecision(2) << roomSubtotal << "\n";
                cout << left << setw(22) << "Amenities Charges:" << "PKR " << fixed << setprecision(2) << amenitiesTotal << "\n";
                cout << "--------------------------------------------------------\n";
                cout << left << setw(22) << "Current Subtotal:" << "PKR " << fixed << setprecision(2) << (roomSubtotal + amenitiesTotal) << "\n";
                cout << "--------------------------------------------------------\n";
                break;
            }

            // 5. Checkout and invoice settlement
            case 5: {
                cout << "\n========================================================\n";
                cout << "           GUEST CHECK-OUT & BILL SETTLEMENT            \n";
                cout << "========================================================\n";

                if (!hasActiveBooking) {
                    cout << "[ALERT] No guest is currently checked in to check out!\n";
                    break;
                }

                double grossBill = roomSubtotal + amenitiesTotal;
                discountRate = 0.0;

                // Stay discount if stay is more than 5 days
                if (stayDays > 5) {
                    discountRate += 0.10; // 10% discount
                    cout << "[DISCOUNT APPLIED] 10% Extended Stay Discount awarded!\n";
                }

                // Check promo code
                char hasPromo = 'N';
                cout << "Do you have a Corporate Promo Code? (Y/N): ";
                cin >> hasPromo;

                if (hasPromo == 'Y' || hasPromo == 'y') {
                    string promoCode = "";
                    cout << "Enter Promo Code: ";
                    cin >> promoCode;
                    
                    if (promoCode == "SZABIST2024" || promoCode == "HORIZON5") {
                        discountRate += 0.05; // Extra 5% discount
                        cout << "[PROMO APPLIED] Extra 5% VIP Discount added successfully!\n";
                    } else {
                        cout << "[INVALID] Promo code unrecognized. No additional discount.\n";
                    }
                }

                discountAmount = grossBill * discountRate;
                double billAfterDiscount = grossBill - discountAmount;
                taxAmount = billAfterDiscount * GST_TAX_RATE;
                grandTotal = billAfterDiscount + taxAmount;

                // Print official invoice
                cout << "\n========================================================\n";
                cout << "                    OFFICIAL INVOICE                    \n";
                cout << "             GRAND HORIZON HOTEL & RESIDENCY            \n";
                cout << "========================================================\n";
                cout << left << setw(20) << "Guest Name:" << guestName << "\n";
                cout << left << setw(20) << "Contact:" << guestPhone << "\n";
                cout << left << setw(20) << "Room Reserved:" << roomName << "\n";
                cout << left << setw(20) << "Duration:" << stayDays << " Night(s)\n";
                cout << "--------------------------------------------------------\n";
                cout << left << setw(32) << "Description" << right << setw(22) << "Amount (PKR)\n";
                cout << "--------------------------------------------------------\n";

                // Day by day room charge breakdown
                for (int day = 1; day <= stayDays; ++day) {
                    cout << left << "  Night " << setw(2) << day << " Room Charge"
                         << right << setw(34) << fixed << setprecision(2) << roomRate << "\n";
                }

                cout << left << "  Room Base Total" << right << setw(37) << fixed << setprecision(2) << roomSubtotal << "\n";
                
                // Amenities breakdown
                if (breakfastOrders > 0) {
                    cout << left << "  Breakfast Buffet (" << breakfastOrders << "x)" 
                         << right << setw(27) << (breakfastOrders * PRICE_BREAKFAST) << "\n";
                }
                if (dinnerOrders > 0) {
                    cout << left << "  Dinner Orders (" << dinnerOrders << "x)" 
                         << right << setw(30) << (dinnerOrders * PRICE_DINNER) << "\n";
                }
                if (laundryItems > 0) {
                    cout << left << "  Laundry Service (" << laundryItems << "x)" 
                         << right << setw(28) << (laundryItems * PRICE_LAUNDRY) << "\n";
                }
                if (shuttleService) {
                    cout << left << "  Airport Shuttle Transfer" 
                         << right << setw(28) << PRICE_SHUTTLE << "\n";
                }

                cout << "--------------------------------------------------------\n";
                cout << left << setw(32) << "Gross Subtotal:" << right << setw(22) << grossBill << "\n";
                cout << left << setw(32) << "Discount Deducted:" << right << setw(22) << -discountAmount << "\n";
                cout << left << setw(32) << "Government Tax (13% GST):" << right << setw(22) << taxAmount << "\n";
                cout << "========================================================\n";
                cout << left << setw(32) << "NET PAYABLE AMOUNT:" << right << setw(22) << grandTotal << "\n";
                cout << "========================================================\n";

                // Take payment from guest and give change
                double cashPaid = 0.0;
                while (cashPaid < grandTotal) {
                    cout << "Enter Cash Amount Tendered (PKR): ";
                    cin >> cashPaid;

                    if (cashPaid < grandTotal) {
                        cout << "[INSUFFICIENT] Amount paid is less than PKR " 
                             << fixed << setprecision(2) << grandTotal 
                             << ". Balance remaining: PKR " << (grandTotal - cashPaid) << "\n";
                    }
                }

                double changeDue = cashPaid - grandTotal;
                cout << "Change Returned to Guest: PKR " << fixed << setprecision(2) << changeDue << "\n";
                cout << "--------------------------------------------------------\n";
                cout << "Thank you for staying at Grand Horizon Hotel! Safe travels!\n";
                cout << "========================================================\n";

                // Update session totals
                totalBookingsCount++;
                totalRevenueCollected += grandTotal;

                // Reset booking state for next guest
                hasActiveBooking = false;
                guestName = "";
                guestPhone = "";
                roomType = 0;
                roomSubtotal = 0.0;
                amenitiesTotal = 0.0;
                break;
            }

            // 6. View statistics
            case 6: {
                cout << "\n--------------------------------------------------------\n";
                cout << "             HOTEL SESSION AUDIT & METRICS              \n";
                cout << "--------------------------------------------------------\n";
                cout << left << setw(32) << "Completed Guest Bookings:" 
                     << right << setw(10) << totalBookingsCount << "\n";
                cout << left << setw(32) << "Cumulative Net Revenue:" 
                     << "PKR " << right << setw(15) << fixed << setprecision(2) << totalRevenueCollected << "\n";
                cout << left << setw(32) << "Active Checked-in Guest:" 
                     << right << setw(20) << (hasActiveBooking ? guestName : "None (Vacant)") << "\n";
                cout << "--------------------------------------------------------\n";

                // Performance status
                cout << "Daily Performance Status: ";
                if (totalBookingsCount == 0) {
                    cout << "Quiet Day\n";
                } else if (totalBookingsCount <= 3) {
                    cout << "Moderate Activity\n";
                } else {
                    cout << "High Occupancy Busy Day\n";
                }

                for (int r = 1; r <= 2; ++r) {
                    cout << "  ";
                    for (int c = 1; c <= 25; ++c) {
                        cout << "*";
                    }
                    cout << "\n";
                }
                break;
            }

            // 7. Exit system
            case 7:
                cout << "\nExiting Hotel Management System. Have a nice day!\n";
                break;

            default:
                cout << "\n[ERROR] Invalid option selected! Please choose between 1 and 7.\n";
                break;
        }

    } while (menuChoice != 7);

    return 0;
}
