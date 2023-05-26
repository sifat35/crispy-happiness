This is a program to generate url for various tasks like acquiring informations about different media, searching in downloadable sites and so on. There is an option to open the genarated url in the default browser for convinience. (only for windows.)


There is a main class "media", which is inherited by "sports", "video"(movie/series), "audio"(song), "book" and "game". The sports class has two child classes, "cricket" and "football. Each class has a parameterized constructor which prints the choices at each stage and completes the tasks picked by the users. the constructors contains infiniye loop which keeps showing the options untill the use picks the "Go back" option, in which case the terminal goes back to the previous stage (if exists) or end the program.


The "media" class contains the functions for taking queries, genarating, printing and opening urls. All other classes uses these functions to complete tasks. There is a global function which initiates objects of different classes according to its parameter. Each class constructor is a self contained stage coded for a specefic media. The "media" class uses the initiator funcltion to initiate an object of the class which corresponds to the option picked. The program uses classes, inheritence, default and parametrized constructor, function overloading and virtual functions to perform its tasks.

Here is the complete list of tasks that this program can execute:

        1. Sports
        2. Movie/Series
        3. Song
        4. Book
        5. Game
        

sports:
        1.Search (Team, player, Match, league etc.)
        2.Live stream
        3.Schedule
        

movie/seriess:
        1.Search (movie/series, actor, director etc.)
        2.Stream
        3.Download
        

song:
        1.Search in Youtube
        2.Search in spotify
        

Book:
        1.Search (Book, series, author etc.)
        2.Download/Read online
        3.Comic
        4.Manga
       

Game:
        1.Search (title, series, developer etc.)
        2.Download
        




