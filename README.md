# Movie Browsing and Recommendation System

---

This C++ program implements a movie browsing and recommendation system similar to platforms like IMDb, Letterboxd, and Rotten Tomatoes. Users can browse through a collection of movies, search for movies by various criteria such as name, release date, genre, or rating, and personalize their browsing experience based on their preferred genres and ratings.

---

## Features

1. **User Authentication:** Users can sign up for an account or visit as a guest. Signed-in users have access to additional features such as saving movies to watchlists and accessing user details.

2. **Browsing Options:**
   - Search by Movie Name
   - Search by Movie Release Date
   - Search by Movie Genre
   - Search Top Rated Movies
   - Search by Preferred Rating
   - Display All Movies

3. **Personalization:** Users can personalize their browsing experience by selecting preferred genres and ratings, allowing for tailored movie recommendations.

4. **Movie Details:** Users can view detailed information about each movie, including its title, rating, genre, release date, duration, director, and a brief overview.

5. **Navigation:** Intuitive navigation using arrow keys and menu options for easy browsing through the movie collection.

6. **Data Sources:** Movie data is sourced from CSV files containing information about movie titles, ratings, genres, release dates, durations, directors, and overviews.

---

## Data Structures Used
- Binary Search Tree (BST): Used to organize movie data efficiently based on movie names.
- Hash Table: Implemented for fast retrieval of movies based on release years.
- Stacks: Utilized for maintaining collections of movies during browsing and recommendation processes.
- Maps:Used to organize movie data based on movie name.
- Linked List: Used for storing user preferences, such as preferred genres and watchlists.


---

## How to Use

1. **Sign Up/Login:** Users can sign up for a new account or log in with existing credentials to access personalized features.

2. **Browsing:** Users can browse through movies using various search criteria or simply explore the entire collection.

3. **Personalization:** Users can personalize their browsing experience by selecting preferred genres and ratings.

4. **Movie Details:** Clicking on a movie title provides detailed information about the selected movie.

5. **Navigation:** Use arrow keys or menu options to navigate through the application and browse movies.

6. **Guest Access:** Guests can explore the movie collection without signing in but will have limited access to features such as saving movies to watchlists.

---

## Requirements
- C++ compiler
- Windows operating system (as some platform-specific commands are used, such as `system("cls")`)

---

## Contributors
- Syed Ali Murtaza

---

## Credits
- Movie data sourced from IMDb and other publicly available datasets.

---

Feel free to modify, expand, or enhance the code according to your requirements. If you encounter any issues or have suggestions for improvement, please feel free to contribute or contact me at alimurtazaathar@gmail.com

