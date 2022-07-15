/*
salam, nokati dar khosus barname:
1_ghesmat ha va joziati mesle virayesh moshakhasat be dalil kambud vaght ijad nashode and.
2_dar toole barname be motaghayer hayi mesle <meli> va <ch_meli> barkhord mikonid ke <ch_meli> mokhafafe <char meli> ast.
3_ghesmat hayi az barname mesle ham amal mikonand pas az tozihate bish az had dar movrede code dar ghesmat haye tekrari khod dari mishavad.
leza behtar ast code va tavabe <masalan void> ra az bala be payin barresi konid.
4_agar be har dalili file ha delete shodand barname ra run karde va be bakhshe admin beravid.
5_Thanks for your attention. have a great day :)).

developed by majid.
*/
#include <iostream>

#include <fstream>

#include <string.h>

using namespace std;

void help_list(int x) { // request list help
   if (x == 1) { //bakhsh koli
      cout << "Here is the list: \n";
      cout << "----------------------------------------- \n";
      cout << "bakhshe bimaran: Press 1 \n";
      cout << "bakhshe pezashkan: Press 2 \n";
      cout << "novbat: Press 3 \n";
      cout << "vizit: Press 4 \n";
      cout << "admin: Press 8 \n";
      cout << "bastan barname: Press 9 \n";
      cout << "----------------------------------------- \n";
   } else if (x == 2) { //bakhsh joz'e
      cout << "----------------------------------------- \n";
      cout << "afzoodan: Press 1 \n";
      cout << "search: Press 2 \n";
      cout << "virayesh: Press 3 \n"; 
      cout << "hazf: Press 4 \n"; 
      cout << "----------------------------------------- \n";
   } else if (x == 3) {
      cout << "----------------------------------------- \n";
      cout << "bar asas: \n";
      cout << "code meli: Press 1\n";
      cout << "nam va name khanevadegi: Press 2\n"; 
      cout << "sen: Press 3\n"; 
      cout << "----------------------------------------- \n";
   } else if (x == 4) {
      cout << "----------------------------------------- \n";
      cout << "afzoodan: Press 1 \n";
      cout << "search: Press 2 \n";
      cout << "hazf: Press 3 \n"; 
      cout << "----------------------------------------- \n";
   }
}

int True_code_meli(int x) { //rasti azma'ei kode meli _ agar eshtebah bod 1 ra barmigardanad
   int y = 0;
   if (x / 10000000 == 112)
      y = x;
   return y;
}

void Add_Patient() { //afzoodane bimaran
   cout << "shoma dar hale afzoodan bimar hastid\n";
   //ghesmate code meli
   char ch_meli[30];
   char test[30];
   int eof(), dorosti = 1, meli; //eof = end of file
   ifstream infile;
   infile.open("bimar", ofstream::out | ofstream::app);
   if (infile.is_open()) {
      do {
         do {
            cout << "lotfan code meli ra vared konid: \n";
            cin >> meli;
            meli = True_code_meli(meli);
         } while (meli == 0);
         sprintf(ch_meli, "%d", meli); //tabdil int : [meli] be char : [ch_meli]
         dorosti = 1;
         while (!infile.eof()) { //ta vaghti be entehaye file nareside ast edame midahad
            infile >> test;
            if (strcmp(test, ch_meli) == 0) { //check kardan baraye code meli tekrari
               dorosti = 0;
               cout << "code meli tekrari ast! \n";
               break;
            }
         }
         infile.seekg(0, ios::beg); //pointer ra be ebtedaye file barmigardanim
      } while (dorosti == 0); //agar [dorosti = 1] bod yani code meli tekrari naboode ast
      infile.close();
   }
   //etmame ghesmate code meli
   char name[31], fname[61]; //esm & famil
   cout << "name bimar ra vared konid:  ";
   cin >>name;
   cout << "\n name khanevadegi bimar ra vared konid:  ";
   cin >>fname;

   int year, month, day; //sal & mah & rooz
   do { //sal
      cout << "\n sale tavalode bimar ra vared koni:   ";
      cin >> year;
      if (year / 100 != 13)
         year = 0;
   } while (year == 0);
   do { //mah
      cout << "\n mahe tavalode bimar ra vared koni:   ";
      cin >> month;
   } while ((month < 1) || (month > 12));
   do { //rooz
      cout << "\n roze tavalode bimar ra vared koni:   ";
      cin >> day;
   } while ((day < 1) || (day > 30));

   long long int phone;
   do { //shomare
      cout << "\n shomare bimar ra vared konid:    ";
      cin >> phone;
      if (phone / 1000000000 != 9)
         phone = 0;
      else if (phone / 10000000000 != 0)
         phone = 0;
   } while (phone == 0);

   ofstream outfile;

   outfile.open("bimar", ofstream::out | ofstream::app); //baz kardan file

   if (outfile.is_open()) {

      //neveshtan moshakhasat
      outfile << meli << endl;
      outfile << name << endl << fname << endl;
      outfile << year << "/" << month << "/" << day << endl;
      outfile << 1400 - year << endl;
      outfile << phone << endl;
      outfile << "1" << endl;
      outfile << "1" << endl;
      outfile << "1" << endl << "1" << endl;

      outfile.close(); //bastan file
   } else
      cout << "ERROR!";

}

void Add_doctor() {
   char ch_meli[30];
   char test[30];
   int eof(), dorosti = 1, meli; //eof = end of file
   ifstream infile;
   infile.open("pezeshk", ofstream::out | ofstream::app);
   if (infile.is_open()) {
      do {
         do {
            cout << "lotfan code meli pezeshk ra vared konid: \n";
            cin >> meli;
            meli = True_code_meli(meli);
         } while (meli == 0);
         sprintf(ch_meli, "%d", meli); //tabdil int : [meli] be char : [ch_meli]
         dorosti = 1;
         while (!infile.eof()) { //ta vaghti be entehaye file nareside ast edame midahad
            infile >> test;
            if (strcmp(test, ch_meli) == 0) { //check kardan baraye code meli tekrari
               dorosti = 0;
               cout << "code meli tekrari ast! \n";
               break;
            }
         }
         infile.seekg(0, ios::beg); //pointer ra be ebtedaye file barmigardanim
      } while (dorosti == 0); //agar [dorosti = 1] bod yani code meli tekrari naboode ast
      infile.close();
   }
   char name[31], fname[61]; //esm va famil
   cout << "name pezeshk ra vared konid:  ";
   cin >> name;
   cout << "\n name khanevadegi pezeshk ra vared konid:  ";
   cin >> fname;

   ofstream outfile;

   outfile.open("pezeshk", ofstream::out | ofstream::app); //baz kardan file

   if (outfile.is_open()) {

      //neveshtan moshakhasat
      outfile << ch_meli << endl;
      outfile << name << endl << fname << endl;
      outfile << "1" << endl << "1" << endl;

      outfile.close(); //bastan file
   } else
      cout << "ERROR!";
}

void search_Patient() { //search bimaran
   cout << "shoma dar hale peyda kardane bimar hastid! \n";
   help_list(3);
   int x;
   do {
      cout << "lotfan darkhast ra vared konid:    ";
      cin >> x;
   } while ((x != 1) && (x != 2) && (x != 3));

   //ghesmate search ba code meli
   if (x == 1) {

      int eof();
      int meli;
      int stop = 1;
      char ch_meli[90];
      char test[90];
      ifstream infile;
      do {
         infile.open("bimar", ofstream::out | ofstream::app);
         if (infile.is_open()) {

            do {
               cout << "lotfan code meli bimar ra vared konid: \n";
               cin >> meli;
               meli = True_code_meli(meli);
            } while (meli == 0);
            sprintf(ch_meli, "%d", meli);

            while (!infile.eof()) {
               infile >> test;
               if (strcmp(test, ch_meli) == 0) { //code meli ke peyda shod khat haye badi ra chap mikonim
                  cout << "------" << endl;
                  puts(test);
                  for (int i = 0; i < 5; i++) {
                     infile >> test;
                     puts(test);
                  }
                  cout << "------" << endl;
                  stop = 0;
                  break;

               }
            }
            if (stop == 1) {
               cout << "code meli vojod nadarad! \n";
            }

            infile.seekg(0, ios::beg);
            infile.close();
         }
      } while (stop == 1);
   }
   //etmame ghesmate search ba code meli

   //search ba name va fname
   if (x == 2) {
      char name[90];
      char fname[90];

      int eof();
      int count = 1;
      int stop = 1;
      char test[90];
      ifstream infile;
      do {
         infile.open("bimar", ofstream::out | ofstream::app);
         if (infile.is_open()) {
            cout << "lotfan name bimar ra vared konid:   ";
            cin >> name;
            cout << "lotfan name khanevadegi bimar ra vared konid:   ";
            cin >> fname;

            while (!infile.eof()) {
               infile >> test;
               count += 1; //ba <count> makane moshakhasate movrede nazar ra peyda mikonim
               if (strcmp(test, name) == 0) {
                  infile >> test;
                  if (strcmp(test, fname) == 0) { //agar name dorost bood fname ra ham check mikonim
                     stop = 0;
                     break;
                  }
               }
            }
            if (stop == 1) {
               cout << "bimari ba in moshakhasat vojod nadarad! \n";
               count = 1;
            }

            infile.seekg(0, ios::beg);
            infile.close();
         }
      } while (stop == 1);
      cout << endl << "-------" << endl;
      char information[90];
      infile.open("bimar", ofstream::out | ofstream::app);
      if (infile.is_open()) {

         for (int i = 1; i < count - 1; i++) //ba tavajoh be <count> etela'at ra chap mikonim
            infile >> information;

         puts(information);
         for (int i = 0; i < 5; i++) {
            infile >> information;
            puts(information);
         }

      }

      cout << "------ \n";
   }

   //ba sen
   if (x == 3) {

      char ch_sen[90];
      int sen;

      int eof();
      int count = 1;
      int stop = 1;
      char test[90];
      ifstream infile;
      do {
         infile.open("bimar", ofstream::out | ofstream::app);
         if (infile.is_open()) {

            do {
               cout << "sen bimar ra vared konid:    ";
               cin >> sen;
            } while ((sen < 2) || (sen > 100));
            sprintf(ch_sen, "%d", sen);

            infile >> test; //2 khate avale file ra hesab nakonad
            infile >> test;

            while (!infile.eof()) {
               infile >> test;
               count += 1;
               if (strcmp(test, ch_sen) == 0) {
                  stop = 0;
                  break;

               }
            }
            if (stop == 1) {
               cout << "bimari ba in moshakhasat vojod nadarad! \n";
               count = 1;
            }

            infile.seekg(0, ios::beg);
            infile.close();
         }
      } while (stop == 1);
      cout << endl << "-------" << endl;
      char information[90];
      infile.open("bimar", ofstream::out | ofstream::app);
      if (infile.is_open()) {

         for (int i = 1; i < count - 2; i++)
            infile >> information;

         puts(information);
         for (int i = 0; i < 5; i++) {
            infile >> information;
            puts(information);
         }

      }

      cout << "------ \n";
   }

}

void search_doctor() {
   cout << "shoma dar hale peyda kardane pezeshk hastid! \n";
   cout << "bar asase:   \n";
   cout << "code meli: Press 1   \n";
   cout << "nam va name khanevadegi: Press 2  \n";
   int x;
   do {
      cout << "lotfan darkhast ra vared konid:    ";
      cin >> x;
   } while ((x != 1) && (x != 2));

   //code meli
   if (x == 1) {

      int eof();
      int meli;
      int stop = 1;
      char ch_meli[90];
      char test[90];
      ifstream infile;
      do {
         infile.open("pezeshk", ofstream::out | ofstream::app);
         if (infile.is_open()) {

            do {
               cout << "lotfan code meli pezeshk ra vared konid: \n";
               cin >> meli;
               meli = True_code_meli(meli);
            } while (meli == 0);
            sprintf(ch_meli, "%d", meli);

            while (!infile.eof()) {
               infile >> test;
               if (strcmp(test, ch_meli) == 0) {
                  cout << "------" << endl;
                  puts(test);
                  infile >> test;
                  puts(test);
                  infile >> test;
                  puts(test);
                  cout << "------" << endl;
                  stop = 0;
                  break;

               }
            }
            if (stop == 1) {
               cout << "code meli vojod nadarad! \n";
            }

            infile.seekg(0, ios::beg);
            infile.close();
         }
      } while (stop == 1);
   }
   //etmame search ba code meli

   //search ba name va fname
   if (x == 2) {
      char name[90];
      char fname[90];

      int eof();
      int count = 1;
      int stop = 1;
      char test[90];
      ifstream infile;
      do {
         infile.open("pezeshk", ofstream::out | ofstream::app);
         if (infile.is_open()) {
            cout << "lotfan name pezeshk ra vared konid:   ";
            cin >> name;
            cout << "lotfan name khanevadegi pezeshk ra vared konid:   ";
            cin >> fname;

            while (!infile.eof()) {
               infile >> test;
               count += 1;
               if (strcmp(test, name) == 0) {
                  infile >> test;
                  if (strcmp(test, fname) == 0) {
                     stop = 0;
                     break;
                  }
               }
            }
            if (stop == 1) {
               cout << "pezeshki ba in moshakhasat vojod nadarad! \n";
               count = 1;
            }

            infile.seekg(0, ios::beg);
            infile.close();
         }
      } while (stop == 1);
      cout << endl << "-------" << endl;
      char information[90];
      infile.open("pezeshk", ofstream::out | ofstream::app);
      if (infile.is_open()) {

         for (int i = 1; i < count - 1; i++)
            infile >> information;

         puts(information);
         for (int i = 0; i < 2; i++) {
            infile >> information;
            puts(information);
         }

      }

      cout << "------ \n";
   }

}

void shomare_nobat() { //afzoodane shomare nobat baraye bimar
   cout << "shoma dar hale gereftane shomare nobat hastid!" << endl;
   cout << "####" << endl << "bimar va pezeshk bayad az ghabl sabt shode bashand!!" << endl;
   int rq;
   do {
      cout << "baraye edame (1), sabte bimar (2) va sabt pezeshk (3) ra feshar dahid:  ";
      cin >> rq;
   } while ((rq != 1) && (rq != 2) && (rq != 3));
   if (rq == 2) {
      rq = 1;
      Add_Patient();
   } else if (rq == 3) {
      rq = 1;
      Add_doctor();
   }

   cout << "---------" << endl;
   int meli;
   char ch_p_meli[30]; //mokhafafe=char patient code meli
   char test[90];
   int eof(), dorosti = 0;
   do {

      do {
         cout << "lotfan code meli bimar ra vared konid: \n";
         cin >> meli;
         meli = True_code_meli(meli);
      } while (meli == 0);
      sprintf(ch_p_meli, "%d", meli);

      ifstream infile;
      infile.open("bimar", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_p_meli) == 0) {
               cout << "code meli ezafe shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "code meli vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
      infile.seekg(0, ios::beg);
   } while (dorosti == 0);
   //entehaye gereftane code meli bimar
   //gereftane code meli doctor
   char ch_d_meli[30]; //mokhafafe=char doctor code meli
   dorosti = 0;
   do {
      do {
         cout << "lotfan code meli pezeshk ra vared konid: \n";
         cin >> meli;
         meli = True_code_meli(meli);
      } while (meli == 0);
      sprintf(ch_d_meli, "%d", meli);

      ifstream infile;
      infile.open("pezeshk", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_d_meli) == 0) {
               cout << "code meli ezafe shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "code meli vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
      infile.seekg(0, ios::beg);
   } while (dorosti == 0);
   //etmame gereftane code meli doctor
   int nobat, month, day, hr, min;
   ifstream infile; //file <nobat-info> baraye dastresi rahat be etela'ate akharin nobat ast
   infile.open("nobat-info", ofstream::out | ofstream::app); //hame etela'ate nobat ghabli ra mikhanim ta nobat jadid ra ijad konim
   if (infile.is_open()) {
      infile >> nobat;
      infile >> month;
      infile >> day;
      infile >> hr;
      infile >> min;
      infile.close();
   } else
      cout << "ERROR!";

   nobat += 1; //etela'at ra be rooz mikonim
   min += 30;
   if (min == 60) {
      hr += 1;
      min = 0;
   }
   if (hr > 20) {
      day += 1;
      hr = 9;
   }
   if (day == 31) {
      month += 1;
      day = 30;
   }

   ofstream outfile;
   outfile.open("nobat-info"); //etela'ate nobate jadid ra jayegozin mikonim
   if (outfile.is_open()) {
      outfile << nobat << endl;
      outfile << month << endl;
      outfile << day << endl;
      outfile << hr << endl;
      outfile << min;

      outfile.close();
   } else
      cout << "ERROR!";

   outfile.open("nobat", ofstream::out | ofstream::app); //moshakhasate nobat ra save mikonim
   if (outfile.is_open()) {
      outfile << nobat << endl;
      outfile << ch_p_meli << endl;
      outfile << ch_d_meli << endl;
      outfile << month << endl;
      outfile << day << endl;
      outfile << hr << endl;
      outfile << min << endl;
      outfile << "1" << endl << "1" << endl << "1" << endl;

      outfile.close();

      cout << "------" << endl << "amaliat ba movafaghiat anjam shod! \n" << "shomare nobat shoma: " << nobat << endl;
   }
}

void delete_nobat() { //hazfe nobati ke az ghabl ijad shode
   cout << "shoma dar hale hazfe nobat hastid! \n" << "------- \n";

   int code;
   char ch_code[30];
   char test[90];
   int eof(), dorosti = 0;
   do {

      do {
         cout << "lotfan somare nobat ra vared konid: \n";
         cin >> code;
      } while (code / 1000 != 1);
      sprintf(ch_code, "%d", code);

      ifstream infile;
      infile.open("nobat", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_code) == 0) { //shomare nobat ra miyabim
               cout << "shomare nobat yaft shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "shomare nobat vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
      infile.seekg(0, ios::beg); 
   } while (dorosti == 0);

   int i;
   do {
      cout << endl << "aya az hazfe shomare nobat motma'een hastid? baraye edame <1> va baraye bazgasht be menu <2> ra feshar dehid." << endl;
      cin >> i;
   } while ((i != 1) && (i != 2));

   if (i == 2)
      cout << "shomare nobat hazf nashod! \n";

   else if (i == 1) {

      ofstream outfile;
      ifstream infile;

      outfile.open("copy.text"); //file <copy.text> baraye copy kardane file ha dar an estefade mishavad

      infile.open("nobat", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile)) //dar soorate baz nashodane file ha
         cout << "ERROR";

      char copy[90];
      int y = 1;
      while (!infile.eof()) { //kole file (be joz moshakhasate nobate dar hale hazf) ra dar <copy.text> copy mikonim
         infile >> copy;

         if (strcmp(copy, ch_code) == 0) {
            for (y = 1; y < 10; y++) {
               infile >> test;
            }
         }
         if (y > 2) {
            infile >> copy;
            y = 0;
         }

         outfile << copy << endl;

      }

      infile.close();
      outfile.close(); //ta inja nobat hazf va file dar <copy.text> copy mishavad

      //<copy.text> ra dar file asli mirizim

      outfile.open("nobat");
      infile.open("copy.text", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile))
         cout << "ERROR";

      while (!infile.eof()) {
         infile >> copy;
         outfile << copy << endl;
      }

      infile.close();
      outfile.close();

      cout << "shomare nobat ba movafaghiat hazf shod. \n";
   }

}

void search_nobat() { //baraye peyda kardane nobat
   cout << "shoma dar hale peyda kardane nobat hastid!" << endl << "#####" << endl;

   int eof();
   int nobat;
   int stop = 1;
   char ch_nobat[90];
   char test[90];
   int month, day, hr, min;
   char bimar[90];
   char pezeshk[90];
   ifstream infile;
   do {
      infile.open("nobat", ofstream::out | ofstream::app);
      if (infile.is_open()) {

         do {
            cout << "lotfan shomare nobat bimar ra vared konid: \n";
            cin >> nobat;
         } while (nobat / 1000 != 1);
         sprintf(test, "%d", nobat);

         while (!infile.eof()) {
            infile >> ch_nobat;
            if (strcmp(test, ch_nobat) == 0) {
               infile >> bimar;
               infile >> pezeshk;
               infile >> month;
               infile >> day;
               infile >> hr;
               infile >> min;
               stop = 0;
               break;

            }
         }
         if (stop == 1) {
            cout << "shomare nobat vojod nadarad! \n";
         }

         infile.seekg(0, ios::beg);
         infile.close();
      }
   } while (stop == 1);
   //chape etelaate nobat
   cout << "------" << endl << "shomare nobat:" << nobat << endl;
   cout << "moshakhasate bimar:" << endl;
   //bimar
   infile.open("bimar", ofstream::out | ofstream::app);
   if (infile.is_open()) {
      do {
         infile >> test;
      } while (strcmp(test, bimar) != 0);
      puts(test);
      for (int i = 0; i < 5; i++) {
         infile >> test;
         puts(test);
      }
      infile.close();
   }
   //bimar

   cout << endl << "moshakhasate pezeshk:" << endl;
   //pezeshk
   infile.open("pezeshk", ofstream::out | ofstream::app);
   if (infile.is_open()) {
      do {
         infile >> test;
      } while (strcmp(test, pezeshk) != 0);
      puts(test);
      infile >> test;
      puts(test);
      infile >> test;
      puts(test);
      infile.close();
   }
   //pezeshk

   cout << endl << "zamane vorood: " << "1400/" << month << "/" << day << "    " << hr << "/" << min << endl;

   min += 30;
   if (min == 60) {
      min = 0;
      day += 1;
   }

   cout << "zamane khorooj: " << "1400/" << month << "/" << day << "    " << hr << "/" << min << endl;

   cout << "------" << endl;
}

void delete_doctor() {
   cout << "shoma dar hale hazf kardane pezeshk hastid!" << endl << "-----" << endl;
   //gereftane code meli

   int meli;
   char ch_d_meli[30];
   char test[90];
   int eof(), dorosti = 0;
   do {

      do {
         cout << "lotfan code meli pezeshk ra vared konid: \n";
         cin >> meli;
         meli = True_code_meli(meli);
      } while (meli == 0);
      sprintf(ch_d_meli, "%d", meli);

      ifstream infile;
      infile.open("pezeshk", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_d_meli) == 0) {
               cout << "code meli yaft shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "code meli vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
   } while (dorosti == 0);
   //payane gereftane code meli
   int i;
   do {
      cout << endl << "aya az hazfe pezeshk motma'een hastid? baraye edame <1> va baraye bazgasht be menu <2> ra feshar dehid." << endl;
      cin >> i;
   } while ((i != 1) && (i != 2));

   if (i == 2)
      cout << "shoma amaliat ra motavaghef kardid! \n";

   else if (i == 1) {

      ofstream outfile;
      ifstream infile;

      outfile.open("copy.text");

      infile.open("pezeshk", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile)) //dar soorate baz nashodane file ha
         cout << "ERROR";

      char copy[90];
      int y = 1;
      while (!infile.eof()) {
         infile >> copy;

         if (strcmp(copy, ch_d_meli) == 0) {
            for (y = 1; y < 5; y++) {
               infile >> copy;
            }
         }
         if (y > 2) {
            infile >> copy;
            y = 0;
         }

         outfile << copy << endl;

      }

      infile.close();
      outfile.close(); //ta inja doctor hazf va file dar <copy.text> copy mishavad

      //<copy.text> ra dar file asli mirizim

      outfile.open("pezeshk");
      infile.open("copy.text", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile))
         cout << "ERROR";

      while (!infile.eof()) {
         infile >> copy;
         outfile << copy << endl;
      }

      infile.close();
      outfile.close();

      cout << "pezeshk ba movafaghiat hazf shod. \n";
   }

}

void Delete_Patient() { //hazfe bimaran
   cout << "shoma dar hale hazf kardane bimar hastid!" << endl << "-----" << endl;
   //gereftane code meli

   int meli;
   char ch_p_meli[30];
   char test[90];
   int eof(), dorosti = 0;
   do {

      do {
         cout << "lotfan code meli bimar ra vared konid: \n";
         cin >> meli;
         meli = True_code_meli(meli);
      } while (meli == 0);
      sprintf(ch_p_meli, "%d", meli);

      ifstream infile;
      infile.open("bimar", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_p_meli) == 0) {
               cout << "code meli yaft shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "code meli vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
      infile.seekg(0, ios::beg); 
   } while (dorosti == 0);
   //payane gereftane code meli
   int i;
   do {
      cout << endl << "aya az hazfe bimar motma'een hastid? baraye edame <1> va baraye bazgasht be menu <2> ra feshar dehid." << endl;
      cin >> i;
   } while ((i != 1) && (i != 2));

   if (i == 2)
      cout << "shoma amaliat ra motavaghef kardid! \n";

   else if (i == 1) {

      ofstream outfile;
      ifstream infile;

      outfile.open("copy.text");

      infile.open("bimar", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile)) //dar soorate baz nashodane file ha
         cout << "ERROR";

      char copy[90];
      int y = 1;
      while (!infile.eof()) {
         infile >> copy;

         if (strcmp(copy, ch_p_meli) == 0) {
            for (y = 1; y < 10; y++) {
               infile >> copy;
            }
         }
         if (y > 2) {
            infile >> copy;
            y = 0;
         }

         outfile << copy << endl;

      }

      infile.close();
      outfile.close(); //ta inja bimar hazf va file dar <copy.text> copy mishavad

      //<copy.text> ra dar file asli mirizim

      outfile.open("bimar");
      infile.open("copy.text", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile))
         cout << "ERROR";

      while (!infile.eof()) {
         infile >> copy;
         outfile << copy << endl;
      }

      infile.close();
      outfile.close();

      cout << "bimar ba movafaghiat hazf shod. \n";
   }
}

void add_visit() { //afzodane visit baraye bimar
   cout << "shomar dar hale afzoodane visit baraye bimar hastid! \n" << endl;
   cout << "####" << endl << "bimar va pezeshk bayad az ghabl sabt shode bashand!!" << endl << "####" << endl;
   int rq;
   do {
      cout << "baraye edame (1), sabte bimar (2) va sabt pezeshk (3) ra feshar dahid:  ";
      cin >> rq;
   } while ((rq != 1) && (rq != 2) && (rq != 3));

   if (rq == 2) {
      Add_Patient();
   } else if (rq == 3) {
      Add_doctor();
   }

   int meli;
   char ch_p_meli[30];
   char test[90];
   int eof(), dorosti = 0;
   //bimar
   do {

      do {
         cout << "lotfan code meli bimar ra vared konid: \n";
         cin >> meli;
         meli = True_code_meli(meli);
      } while (meli == 0);
      sprintf(ch_p_meli, "%d", meli);

      ifstream infile;
      infile.open("bimar", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_p_meli) == 0) {
               cout << "code meli ezafe shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "code meli vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
      infile.seekg(0, ios::beg);
   } while (dorosti == 0);
   //bimar

   //doctor
   char ch_d_meli[30];
   dorosti = 0;
   do {
      do {
         cout << "lotfan code meli pezeshk ra vared konid: \n";
         cin >> meli;
         meli = True_code_meli(meli);
      } while (meli == 0);
      sprintf(ch_d_meli, "%d", meli);

      ifstream infile;
      infile.open("pezeshk", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_d_meli) == 0) {
               cout << "code meli ezafe shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "code meli vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
      infile.seekg(0, ios::beg);
   } while (dorosti == 0);
   //doctor

   int min, hr, day, month;
   do {
      cout << "lotfan mahe movrede nazare khod ra vared konid:    ";
      cin >> month;
   } while ((month < 1) || (month > 12));

   do {
      cout << "lotfan rooze movrede nazare khod ra vared konid:    ";
      cin >> day;
   } while ((day < 1) || (day > 30));

   do {
      cout << "lotfan sa'ate movrede nazare khod ra vared konid(az 9 sobh ta 19 asr):    ";
      cin >> hr;
   } while ((hr < 9) || (hr > 19));

   do {
      cout << "modat zamane molaghat ba doctor cheghadr ast?(hade aksar 100 va hade aghal 30 daghighe)    ";
      cin >> min;
   } while ((min < 29) || (min > 101));

   int shomare_visit;
   ifstream infile;
   infile.open("visit-info", ofstream::out | ofstream::app); //az <visit-info> akharin shomare visit ra migirim
   if (infile.is_open()) {
      infile >> shomare_visit;
      infile.close();
   } else
      cout << "ERROR";
   shomare_visit += 1;
   ofstream outfile;
   outfile.open("visit-info");
   if (outfile.is_open()) {
      outfile << shomare_visit;
      outfile.close();
   } else
      cout << "ERROR";

   outfile.open("visit", ofstream::out | ofstream::app);
   if (outfile.is_open()) {
      outfile << shomare_visit << endl;
      outfile << ch_p_meli << endl;
      outfile << ch_d_meli << endl;
      outfile << month << endl << day << endl << hr << endl << min << endl;
      outfile << "1" << endl << "1" << endl << "1" << endl;

      outfile.close();
   }

   cout << "-----" << endl << "amaliat anja shod! \n" << "shomare visit shoma: " << shomare_visit << endl << "-----" << endl;

}

void search_visit() {
   cout << "shoma dar hale peyda kardane moshakhasate visit hastid!" << endl << "#####" << endl;

   int eof();
   int visit;
   int stop = 1;
   char ch_visit[90];
   char test[90];
   char month[90], day[90], hr[90], min[90];
   char bimar[90];
   char pezeshk[90];
   ifstream infile;
   do {
      infile.open("visit", ofstream::out | ofstream::app);
      if (infile.is_open()) {

         do {
            cout << "lotfan code visit bimar ra vared konid: \n";
            cin >> visit;
         } while (visit / 1000 != 1);
         sprintf(test, "%d", visit);

         while (!infile.eof()) {
            infile >> ch_visit;
            if (strcmp(test, ch_visit) == 0) {
               infile >> bimar;
               infile >> pezeshk;
               infile >> month;
               infile >> day;
               infile >> hr;
               infile >> min;
               stop = 0;
               break;

            }
         }
         if (stop == 1) {
            cout << "shomare visit vojod nadarad! \n";
         }

         infile.seekg(0, ios::beg);
         infile.close();
      }
   } while (stop == 1);
   //chape etelaate visit
   cout << "------" << endl << "shomare visit:" << visit << endl;
   cout << "moshakhasate bimar:" << endl;
   //bimar
   infile.open("bimar", ofstream::out | ofstream::app);
   if (infile.is_open()) {
      do {
         infile >> test;
      } while (strcmp(test, bimar) != 0);
      puts(test);
      for (int i = 0; i < 5; i++) {
         infile >> test;
         puts(test);
      }
      infile.close();
   }
   //bimar

   cout << endl << "moshakhasate pezeshk:" << endl;
   //pezeshk
   infile.open("pezeshk", ofstream::out | ofstream::app);
   if (infile.is_open()) {
      do {
         infile >> test;
      } while (strcmp(test, pezeshk) != 0);
      puts(test);
      infile >> test;
      puts(test);
      infile >> test;
      puts(test);
      infile.close();
   }
   //pezeshk

   cout << endl << "tarikhe visit: " << "1400/" << month << "/" << day << endl << "saat :" << hr << endl;

   cout << "modat zamane visit: " << min << endl;
   cout << "------" << endl;
}

void delete_visit() { //hazfe etela'ate visit
   cout << "shoma dar hale hazfe nobate visit hastid! \n" << "------- \n";

   int code;
   char ch_code[30];
   char test[90];
   int eof(), dorosti = 0;
   do {

      do {
         cout << "lotfan somare visit ra vared konid: \n";
         cin >> code;
      } while (code / 1000 != 1);
      sprintf(ch_code, "%d", code);

      ifstream infile;
      infile.open("visit", ofstream::out | ofstream::app);
      if (infile.is_open()) {
         while (!infile.eof()) {
            infile >> test;
            if (strcmp(test, ch_code) == 0) {
               cout << "shomare visit yaft shod!" << endl;
               dorosti = 1;
               break;
            }

         }
         if (dorosti == 0)
            cout << "shomare visit vojod nadarad! \n";
         infile.close();
      } else
         cout << "error";
   } while (dorosti == 0);

   int i;
   do {
      cout << endl << "aya az hazfe shomare visit motma'een hastid? baraye edame <1> va baraye bazgasht be menu <2> ra feshar dehid." << endl;
      cin >> i;
   } while ((i != 1) && (i != 2));

   if (i == 2)
      cout << "shomare visit hazf nashod! \n";

   else if (i == 1) {

      ofstream outfile;
      ifstream infile;

      outfile.open("copy.text");

      infile.open("visit", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile)) 
         cout << "ERROR";

      char copy[90];
      int y = 1;
      while (!infile.eof()) {
         infile >> copy;

         if (strcmp(copy, ch_code) == 0) {
            for (y = 1; y < 9; y++) {
               infile >> test;
            }
         }
         if (y > 2) {
            infile >> copy;
            y = 0;
         }

         outfile << copy << endl;

      }

      infile.close();
      outfile.close(); 

      //<copy.text> ra dar file asli mirizim

      outfile.open("visit");
      infile.open("copy.text", ofstream::out | ofstream::app);

      if ((!outfile) || (!infile))
         cout << "ERROR";

      while (!infile.eof()) {
         infile >> copy;
         outfile << copy << endl;
      }

      infile.close();
      outfile.close();

      cout << "shomare nobat ba movafaghiat hazf shod. \n";
   }
}

void reset_app() { //reset kardane hame file ha. dar vaghe hame file ha ra overwrite mikonad
   ofstream outfile;
   outfile.open("bimar");
   if (outfile.is_open()) {
      outfile << "5" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl;
      outfile.close();
   }

   outfile.open("pezeshk");
   if (outfile.is_open()) {
      outfile << "5" << endl << "1" << endl << "1" << endl << "1" << endl;
      outfile.close();
   }

   outfile.open("visit");
   if (outfile.is_open()) {
      outfile << "5" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl;
      outfile.close();
   }

   outfile.open("nobat");
   if (outfile.is_open()) {
      outfile << "5" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl << "1" << endl;
      outfile.close();
   }

   outfile.open("visit-info");
   if (outfile.is_open()) {
      outfile << "1000";
      outfile.close();
   }

   outfile.open("nobat-info");
   if (outfile.is_open()) {
      outfile << "1000" << endl;
      outfile << "1" << endl;
      outfile << "1" << endl;
      outfile << "9" << endl;
      outfile << "30";
      outfile.close();
   }
   cout << "amaliat anjam shod. \n";
}

int main() { //tabe'e asli
   cout << "----------------------------------WELCOME---------------------------------- \n";
   int order, loop = 1;
   while (loop) { //halghe'ye asli _ main loop
      help_list(1);
      do {
         cout << "Enter youe request: ";
         cin >> order;
      } while ((order != 1) && (order != 2) && (order != 3) && (order != 4) && (order != 9) && (order != 8));

      switch (order) {
      case 1: { //ghesmate bimaran
         help_list(4);
         int x;
         do {
            cout << "Enter your request: \n";
            cin >> x;
         } while ((x != 1) && (x != 2) && (x != 3));
         switch (x) {
         case 1: { //afzoodan
            Add_Patient();
            break;
         }
         case 2: { //search
            search_Patient();
            break;
         }
         case 3: { //delete
            Delete_Patient();
            break;
         }
         }
         break;
      }
      case 2: { //ghesmate doctoran
         help_list(4);
         int x;
         do {
            cout << "Enter your request: \n";
            cin >> x;
         } while ((x != 1) && (x != 2) && (x != 3));
         switch (x) {
         case 1: { //afzoodan
            Add_doctor();
            break;
         }
         case 2: { //search
            search_doctor();
            break;
         }
         case 3: { //delete
            delete_doctor();
            break;
         }

         }
         break;
      }
      case 3: { //ghesmate nobat
         help_list(4);
         int x;
         do {
            cout << "Enter your request: \n";
            cin >> x;
         } while ((x != 1) && (x != 2) && (x != 3));
         switch (x) {
         case 1: { //afzoodan
            shomare_nobat();
            break;
         }
         case 2: { //search
            search_nobat();
            break;
         }
         case 3: { //delete
            delete_nobat();
            break;
         }
         }
         break;
      }
      case 4: { //ghesmate visit
         help_list(4);
         int x;
         do {
            cout << "darkhaste khod ra vared konid: \n";
            cin >> x;
         } while ((x != 1) && (x != 2) && (x != 3));
         switch (x) {
         case 1: { //afzoodan
            add_visit();
            break;
         }
         case 2: { //search
            search_visit();
            break;
         }
         case 3: { //delete
            delete_visit();
            break;
         }
         }
         break;
      }
      case 8: { //ghesmate admin
         cout << "-----------" << endl << "shoma varede bakhshe admin shodid. \n";
         cout << "in bakhsh baraye reset kardane barname dar soorate hargoone moshkel va ya ijade dobare file ha ast! \n";
         cout << "-------tavajoh!!-------" << endl << "dar soorate edame hameye etela'ate app hazf mishavad. \n";
         int x;
         do {
            cout << "baraye edame <555> va sarfe nazar <1> ra feshar dahid:    ";
            cin >> x;
         } while ((x != 555) && (x != 1));
         if (x == 1)
            cout << "-------amaliat motavaghef shod------- \n";
         if (x == 555)
            reset_app();
         break;
      }
      case 9: { //bastane barname
         loop = 0;
      }
      }
      cout << "\n";
   }
   cout << "BYE!!" << endl; //bye :)))
   return 0;
}