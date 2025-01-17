# Auction System

## Project Overview
The Auction System is a C++-based application designed to facilitate online auctions, allowing users to manage items, bids, member profiles, and reviews. This system provides an intuitive and robust interface for both guests and registered members, enabling seamless interaction with auction activities.

### Key Features:
- User Authentication: Login, signup, and role-based access control (e.g., Admin, Guest, Member).
- Item Management: Add, update, and remove auction items.
- Bidding System: Place bids on available items with real-time updates.
- Ratings and Reviews: Members can rate and review items.
- File Management: Persist data using CSV files for items, members, and reviews.

## Team Members
This project was developed by the following talented team members:

- Nguyen Minh Khai - s3995223
- Nguyen Vu Trong Nhan - s4028019
- Duong Hoang Anh Khoa - s3864111
- Ho Gia Bao - s3958122
- Pham Hong Nhat - s3915104


## How to Run
Follow the steps below to set up and run the Auction System:

1. Clone the repository:
   ```bash
   git clone https://github.com/anhkhoa31/auction-system.git
   cd auction-system

2. Complie the project:
g++ -std=c++11 main.cpp \
    application/*.cpp \
    controllers/*.cpp \
    models/*.cpp \
    utils/*.cpp \
    views/*.cpp \
    -o main

3. Run the executable:
./main
github.com
