//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int ballSpeedX = -5,    ballSpeedY = -5;
int palletSpeed = 15;
int hits = 0;
int pointsBlue = 0,     pointsRed = 0;
bool startingProgram = true;

void viewPointScored(){
        Form1->currentHits->Caption = "liczba odbiæ: " + IntToStr(hits);
        Form1->score->Caption = IntToStr(pointsBlue) + " : " + IntToStr(pointsRed);

        Form1->timerBall->Enabled = false;
        Form1->currentPoint->Visible = true;
        Form1->currentHits->Visible = true;
        Form1->score->Visible = true;
        Form1->nextRound->Visible = true;
        Form1->newGame->Visible = true;

        Form1->nextRound->Enabled = true;
        Form1->newGame->Enabled = true;
}

void resumeGame(){
        Form1->currentPoint->Visible = false;
        Form1->currentHits->Visible = false;
        Form1->score->Visible = false;
        Form1->nextRound->Visible = false;
        Form1->newGame->Visible = false;

        Form1->nextRound->Enabled = false;
        Form1->newGame->Enabled = false;

        hits = 0;
        Form1->ball->Left = 245;
        Form1->ball->Top = 293;
        Form1->palletBlue->Left = 215;
        Form1->palletRed->Left = 215;
        Sleep(1000);
        Form1->timerBall->Enabled = true;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
	Application->MessageBox("Witamy w grze PingPong! \n \nNiebieski gracz steruje praw¹ i lew¹ strza³k¹.\nCzerwony gracz steruje klawiszami A i D \nPrêdkoœæ pi³ki zale¿y od przytrzymania klawisza w momencie uderzenia. \n\nMi³ej zabawy!", "PingPong", MB_OK);
        Show();
        Application->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBallTimer(TObject *Sender)
{
        ball->Left += ballSpeedX;
        ball->Top += ballSpeedY;

        //     WALLS BOUNCES
        if(ball->Left-5 <= background->Left)
                ballSpeedX = -ballSpeedX;

        if(ball->Left + ball->Width +5 >= background->Width)
                ballSpeedX = -ballSpeedX;

        //      PALLETS BOUNCES
        if(ball->Left + ball->Width/2 >= palletBlue->Left
           && ball->Left + ball->Width/2 <= palletBlue->Left + palletBlue->Width
           && ball->Top + ball->Height >= palletBlue->Top
           && ballSpeedY > 0){
                ballSpeedY = -ballSpeedY;
                hits++;

                if(timerBlueLeft->Enabled == true)
                        ballSpeedX -= palletSpeed/3;
                else if(timerBlueRight->Enabled == true)
                        ballSpeedX += palletSpeed/3;
                else
                        ballSpeedY -= palletSpeed/3;
        }

        if(ball->Left + ball->Width/2 >= palletRed->Left
           && ball->Left + ball->Width/2 <= palletRed->Left + palletRed->Width
           && ball->Top <= palletRed->Top +palletRed->Height
           && ballSpeedY < 0){
                ballSpeedY = -ballSpeedY;
                hits++;

                if(timerRedLeft->Enabled == true)
                        ballSpeedX -= palletSpeed/3;
                else if(timerRedRight->Enabled == true)
                        ballSpeedX += palletSpeed/3;
                else
                        ballSpeedY += palletSpeed/3;
        }

        //          POINT
        if(ball->Top <= palletRed->Top - 5){
               currentPoint->Caption  = "Punkt dla gracza niebieskiego!";
               currentPoint->Color = clBlue;
               pointsBlue++;
               viewPointScored();
        }
        if(ball->Top + ball->Height >= palletBlue->Top + palletBlue->Height + 5){
               currentPoint->Caption  = "Punkt dla gracza czerwonego!";
               currentPoint->Color = clRed;
               pointsRed++;
               viewPointScored();
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::timerBlueLeftTimer(TObject *Sender)
{
        if(palletBlue->Left > 10)
                palletBlue->Left -= palletSpeed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerBlueRightTimer(TObject *Sender)
{
        if(palletBlue->Left + palletBlue->Width < background->Width - 10)
                palletBlue->Left += palletSpeed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT)
                timerBlueLeft->Enabled = true;

        if(Key == VK_RIGHT)
                timerBlueRight->Enabled = true;

        if(Key == 0x41)
                timerRedLeft->Enabled = true;

        if(Key == 0x44)
                timerRedRight->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_LEFT)
                timerBlueLeft->Enabled = false;

        if(Key == VK_RIGHT)
                timerBlueRight->Enabled = false;

        if(Key == 0x41)
                timerRedLeft->Enabled = false;

        if(Key == 0x44)
                timerRedRight->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerRedLeftTimer(TObject *Sender)
{
        if(palletRed->Left > 10)
                palletRed->Left -= palletSpeed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::timerRedRightTimer(TObject *Sender)
{
        if(palletRed->Left + palletRed->Width < background->Width - 10)
                palletRed->Left += palletSpeed;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
        ballSpeedX = -5;
        if(ballSpeedY < 0 )
                ballSpeedY = -5;
        else
                ballSpeedY = 5;

        resumeGame();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
        if(startingProgram){
            startingProgram = false;
            resumeGame();
        }
        else if(Application->MessageBox("Czy na pewno chcesz zacz¹æ od nowa?", "Nowa gra", MB_YESNO) == IDYES){

                pointsBlue = 0;
                pointsRed = 0;

                ballSpeedX = -5;
                ballSpeedY = -5;

                resumeGame();
        }
}
//---------------------------------------------------------------------------

