//---------------------------------------------------------------------------
//program do odgrywania dzwieku
//Do odgrywania dzwieku potrzebmy nam z zakladki system funkcji mediaplayer
//1 Metoda - plik odgrywa sie caly, nawet przy przycisnieciu w trakcie jego trwania
//2 Metoda - to asynchroniczne odgrywanie, czyli jesli nacisniemy w trakcie to odegra sie od nowa
//najlepiej sprawdzic to samemu w programie

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h" //biblioteka do rozpoznywania funkcji snd przez kompilator

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{  //najpierw wpisujemy metoda mediaplayer
  MediaPlayer1->Play();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//Najpierw tworzymy Events - FromCreate
//i podajemy w tej metodzie sciezke do pliku audio zeby ja zgrac do programu:

MediaPlayer1->FileName = "snd/dzwiek.wav";   //FileName-podfolder snd/nazwa pliku
//teraz nalezy otworzyc ten plik
MediaPlayer1->Open();

// otwarte pliki nalezy pozniej zamknac,
//robimy to w Form1-Events-OnClose :

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   MediaPlayer1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{ //Teraz zrobimy druga metode odgrywania dzwiekow bez MediaPlayera(ikony)
  sndPlaySound("snd/dzwiek.wav",SND_ASYNC); //pierwszym elementem jest nazwa sciezki "snd"
  //Pierwszym argumentem w() jest sciezka oraz stala o nazwie SND_ASYNC czy;li odgrywanie asychronicznych dzwiekow (niezaleznych od zagara)
  //jesli damy SND_SYNC - bedzie odgrywal sie caly dzwiek do konca , nie przerwie go ponowne klikniecie przycisku, jednak kazde klikniecie jest zapisywane i odegra sie tyle razy ile kliknelismy w przycisk

  }
//---------------------------------------------------------------------------
