#include <iostream>
#include <windows.h>
using namespace std;
void class_initializer(char c);
class sports; class cricket; class football; class video; class audio; class book; class game;

class media{
public:
    virtual string info(){};
    string url="";
    media(){}
    media(int i){
        while(true){
        cout<<endl<<"Choose an option to begin:\n\t1. Sports\n\t2. Movie/Series\n\t3. Song\n\t4. Book\n\t5. Game\n\t0. Exit";
        cout<<endl;
        int p; cin>>p;
        if(p==1) class_initializer('s');
        else if(p==2) class_initializer('m');
        else if(p==3) class_initializer('a');
        else if(p==4) class_initializer('b');
        else if(p==5) class_initializer('g');
        else if(p==0){cout<<endl<<"Session ended."; break;}
        else cout<<endl<<"Please choose between 1,2,3,4,5 or 0"<<endl;
        } }
    //virtual string generate_url(string query);
    void open_url(string s){
        char* linkChar= new char[s.size()+2];//"http://www.google.com";
        int i=0;
        for(i=0; s[i] != '\0'; i++){ linkChar[i] = s[i];}
        linkChar[i] = '\0';

        ShellExecute(NULL, NULL, linkChar, NULL, NULL, SW_SHOWNORMAL);
        cout<<endl<<"url opened"<<endl;
    }

    void generate_url(string url_before, string space, string url_after, string input){
        //cout<<endl<<"You have searched for \""<<input<<"\". Here is the url genarated for your search query:";
        string mod_input;
        for(int i=0;input[i] != '\0'; i++){if(input[i] == ' ') mod_input= mod_input + space;
                                        else mod_input += input[i];
        }
        string g_url="";
        g_url =url_before+mod_input+url_after;
        //return url;
        //cout<<endl<<g_url<<endl;
        cout<<endl<<"\t"<<g_url<<endl<<"Do you want to open the url in your default browser[y/n]?: ";
        char c; cin>>c;
        if(c=='y') open_url(g_url);
    }
    void search_url(string url_before, string space, string url_after, string write="You have picked \"search\". Please enter your search query: "){
        cout<<endl<<write;
        string s; getline(cin, s);
        cout<<endl<<"You have searched for \""<<s<<"\". Here is the url genarated for your search query:";
        generate_url( url_before,  space, url_after,  s);
    }
    void put_url(string s){
        cout<<endl<<"Here is the url:\n\t"<<s<<endl<<"Do you want to open the url in your default browser[y/n]?: ";
        char c; cin>>c;
        if(c=='y') open_url(s);
    }
};




class sports: public media{
public:
    sports(){}
    sports(int i): media(){
      while(true){
       cout<<endl;
       cout<<"You have picked \"sports\" catagory. Please choose one of the following sports:\n\t1.Cricket\n\t2.Football\n\t0.Go back";
       cout<<endl;
       int p; cin>>p;
       if(p==1) class_initializer('c');
       else if(p==2) class_initializer('f');
       else if(p==0) break;
       else {cout<<endl<<"Please choose between 1, 2 or 0"<<endl;}
      }
    }
    string live, schedule;
};


class cricket: public sports{
public:
    cricket(int i):sports(){
       while(true){
        cout<<endl<<"you have picked \"cricket\". You have the following options:\n\t1.Search (Team, player, Match, league etc.)\n\t2.Live stream\n\t3.Schedule\n\t0.Go back"<<endl;
        int p; cin>>p; cin.ignore();
        if(p==1){
            search_url("https://search.espncricinfo.com/ci/content/site/search.html?search=", "%20", "");        //https://search.espncricinfo.com/ci/content/site/search.html?search=ban%20vs%20ire
            }
        else if(p==2) put_url("https://redditsport.live/sport/cricket/today");
        else if(p==3) put_url("https://www.espncricinfo.com/ci/content/match/fixtures_futures.html");
        else if(p==0) break;
        else {cout<<endl<<"Please choose between 1, 2, 3 or 0"<<endl;}
    }
  }
};


class football: public sports{
public:
    football(int i):sports(){
       while(true){
        cout<<endl<<"you have picked \"football\". You have the following options:\n\t1.Search (Team, player, Match, league etc.)\n\t2.Live stream\n\t3.Schedule\n\t0.Go back"<<endl;
        int p; cin>>p; cin.ignore();
        if(p==1){
            search_url("https://www.espn.in/search/_/q/", "%20", "");        //https://www.espn.in/search/_/q/real%20betis
            }
        else if(p==2) put_url("https://redditsport.live/index.htm?utm_source=pocket_mylist");
        else if(p==3) put_url("https://www.espn.in/football/schedule");
        else if(p==0) break;
        else {cout<<endl<<"Please choose between 1, 2, 3 or 0"<<endl;}
    }
  }
};




class video: public media{
public:
    video(int i): media(){
        while(true){
            cout<<endl<<"you have picked \"movie/series\". You have the following options:\n\t1.Search (movie/series, actor, director etc.)\n\t2.Stream\n\t3.Download\n\t0.Go back"<<endl;
            int p; cin>>p; cin.ignore();
            if(p==1){
                search_url("https://www.imdb.com/find/?q=", "%20", "&ref_=nv_sr_sm");
            }
            else if(p==2){
                bool br = false;
                while(!br){
                cout<<endl<<"You have picked \"stream\". Please choose from the following catagories:\n\t1.Movie/Series\n\t2.Anime\n\t3.Korean drama\n\t0.Go back"<<endl;
                int q; cin>>q; cin.ignore();
                switch(q){
                case 1:
                    search_url("https://123chill.to/?s=", "+", "&post_type=post%2Ctvshows", "You have picked \"Movie/Series\". Please enter the title: ");
                    break;
                case 2:
                    search_url("https://9anime.gs/filter?keyword=","+", "", "You have picked \"Anime\". Please enter the title: ");
                    break;
                case 3:
                    search_url("https://www.viki.com/search?q=" , "%20", "", "You have picked \"Korean Drama\". Please enter the title: ");
                    break;
                case 0:
                    br= true;
                    break ;
                default:
                    cout<<endl<<"Please choose between 1, 2, 3 or 0"<<endl;
                    break;
                }                                                                         //https://www.viki.com/search?q=walking%20dead
            }
        }
        else if(p==3){
            cout<<endl<<"You have picked \"download\". Please choose from the following options:\n\t1.Torrent (1337x)\n\t2.Direct download (mlwbd)"<<endl;
            int q; cin>>q; cin.ignore();
            switch(q){
            case 1:
                //https://1337x.to/search/portal+2/1/
                search_url("https://1337x.to/search/", "+", "/1/", "You have picked \"Torrent\". Please enter the title: ");
                break;
            case 2:
                //https://mlwbd.top//?s=the+succession
                search_url("https://mlwbd.top//?s=", "+", "", "You have picked \"Direct download\". Please enter the title: ");
                break;
            default:
                    cout<<endl<<"Please choose between 1 or 2"<<endl;
                    break;

            }
        }
        else if(p==0) break;
        else cout<<endl<<"Please choose between 1, 2, 3 or 0"<<endl;
    }
  }
};

class audio: public media{
public:
    audio(int i): media(){
        while(true){
            cout<<endl<<"you have picked \"song\". You have the following options:\n\t1.Search in Youtube\n\t2.Search in spotify\n\t0.Go back"<<endl;
            int p; cin>>p; cin.ignore();
            if(p==1) //https://www.youtube.com/results?search_query=saat+samundar+paar
                search_url("https://www.youtube.com/results?search_query=", "+", "", "You have picked \"search in youtube\". Please enter your search query: ");
            else if(p==2) //https://open.spotify.com/search/dark%20indie
                search_url("https://open.spotify.com/search/", "%20", "", "You have picked \"search in spotify\". Please enter your search query: ");
            else if(p==0) break;
            else cout<<endl<<"Please choose between 1, 2 or 0"<<endl;
        }
    }
};

class book: public media{
public:
    book(int i):media(){
        while(true){
            cout<<endl<<"you have picked \"Book\". You have the following options:\n\t1.Search (Book, series, author etc.)\n\t2.Download/Read online\n\t3.Comic\n\t4.Manga\n\t0.Go back"<<endl;
            int p; cin>>p; cin.ignore();
            if(p==1) //https://www.goodreads.com/search?q=shadow+of+the+wind&qid=QhwwaA7jjL
                search_url("https://www.goodreads.com/search?q=", "+", "&qid=QhwwaA7jjL");
            else if(p==2){
                cout<<endl<<"you have picked \"Download/Read online\". You have the following options:\n\t1.Pdfdrive\n\t2.Justfreebooks"<<endl;
                int q; cin>>q; cin.ignore();
                if(q==1) //https://www.pdfdrive.com/search?q=shadow+of+the+wind&pagecount=&pubyear=&searchin=&em=
                    search_url("https://www.pdfdrive.com/search?q=", "+", "&pagecount=&pubyear=&searchin=&em=", "You have picked \"Pdfdrive\". Please enter the title/author: ");
                else if(q==2) //http://www.justfreebooks.info/results.php?q=art+of+letting+go
                    search_url("http://www.justfreebooks.info/results.php?q=", "+", "", "You have picked \"Justfreebooks\". Please enter the title/author: ");
                else cout<<endl<<"Please choose between 1 or 2"<<endl;
            }
            else if(p==3) //https://readcomiconline.li/AdvanceSearch?comicName=some+say&ig=&eg=&status=
                search_url("https://readcomiconline.li/AdvanceSearch?comicName=", "+", "&ig=&eg=&status=", "You have picked \"Comics\". Please enter the title/author: ");
            else if(p==4) //https://mangadex.org/search?q=20th+century+boys
                search_url("https://mangadex.org/search?q=", "+", "", "You have picked \"Manga\". Please enter the title/author: ");
            else if(p==0) break;
            else cout<<endl<<"Please choose between 1,2,3,4 or 0"<<endl;
        }
    }
};


class game: public media{
public:
    game(int i): media(){
        while(true){
            cout<<endl<<"you have picked \"Game\". You have the following options:\n\t1.Search (title, series, developer etc.)\n\t2.Download\n\t0.Go back"<<endl;
            int p; cin>>p; cin.ignore();
            if(p==1) //https://www.metacritic.com/search/game/the%20room/results
                search_url("https://www.metacritic.com/search/game/", "%20", "/results");
            else if(p==2){
                cout<<endl<<"you have picked \"download\". You have the following options:\n\t1.Torrent (fitgirl repack)\n\t2.Gog release"<<endl;
                int q; cin>>q; cin.ignore();
                if(q==1) //https://fitgirl-repacks.site/?s=god+of+war
                    search_url("https://fitgirl-repacks.site/?s=", "+", "", "You have picked \"torrent\". Please enter the title: ");
                else if(q==2) //https://gog-games.to/search/portal%202
                     search_url("https://gog-games.to/search/", "%20", "", "You have picked \"gog release\". Please enter the title: ");
                else cout<<endl<<"Please choose between 1 or 2"<<endl;
            }
            else if(p==0) break;
            else cout<<endl<<"Please choose between 1,2 or 0"<<endl;
        }
    }
};



void class_initializer(char ch){
    switch (ch){
    case 's':
        {
        sports objs(1);
        break;
        }
    case 'c':
        {
        cricket objc(1);
        break;
        }
    case 'f':
        {
        football objf(1);
        break;
        }
    case 'm':
        {
        video objv(1);
        break;
        }
    case 'a':
        {
        audio obja(1);

        break;
        }
    case 'b':
        {
        book objb(1);
        break;
        }
    case 'g':
        {
        game objg(1);
        break;
        }

    }
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    media objm(1);
}

