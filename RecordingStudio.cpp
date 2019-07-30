
#include <iostream>
#include <string>
#include <mysql.h>
#include <conio.h>

using namespace std;

MYSQL_RES* runQuery(string query);
void showRes(MYSQL_RES* res);
void countAlnumsBetweenTwoDates();
void countMusicianSongsBetweenTwoDates();
void countMusicianAlbumsBetweenTwoDates();
void popularInstrument();
void showAlbumInstruments();
void popularProducer();
void popularInstrumentManufacturer();
void musiciansNumber();
void musicianPlay();
void popularGenre();
void popularTechnicianBetweenTwoDates();
void firstAlbum();
void albumHave2Songs();
void fullTechAlbum();
void mostVersatileMusician();

MYSQL* conn;
int qstate;

int main()
{
	bool flag = true;
	int choice;
	string x;

	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", "root", "", "recording_studio", 3306, NULL, 0);

	if (conn) {
		cout << "connection to database saccess, database is ready" << endl << endl;

		while (flag)
		{
			cout << "Select an action number:" << endl
				<< "1.  count albums between two dates" << endl
				<< "2.  count musecian songs between two dates" << endl
				<< "3.  count musecian albums between two dates" << endl
				<< "4.  popular musical instrument" << endl
				<< "5.  show musical instruments of selected album" << endl
				<< "6.  popular producer between two dates" << endl
				<< "7.  popular musical instrument manufacturer" << endl
				<< "8.  musecians number" << endl
				<< "9.  the nmusician that playin with biggest number of musicians" << endl
				<< "10. musecians number" << endl
				<< "11. popular technecian between two dates" << endl
				<< "12. first album" << endl
				<< "13. show albums that hav at least two songs" << endl
				<< "14. full technician album songs" << endl
				<< "15. the most versatile musician" << endl
				<< "16.exit" << endl;

			cout << "enter the number of the choice please:";
			cin >> choice;

			//clear console
			system("cls");

			switch (choice)
			{
				case 1:
					countAlnumsBetweenTwoDates();
					break;
				case 2:
					countMusicianSongsBetweenTwoDates();
					break;
				case 3:
					countMusicianAlbumsBetweenTwoDates();
					break;
				case 4:
					popularInstrument();
					break;
				case 5:
					showAlbumInstruments();
					break;
				case 6:
					popularProducer();
					break;
				case 7:
					popularInstrumentManufacturer();
					break;
				case 8:
					musiciansNumber();
					break;
				case 9:
					musicianPlay();
					break;
				case 10:
					popularGenre();
					break;
				case 11:
					popularTechnicianBetweenTwoDates();
					break;
				case 12:
					firstAlbum();
					break;				
				case 13:
					albumHave2Songs();
					break;
				case 14:
					fullTechAlbum();
					break;
				case 15:
					mostVersatileMusician();
					break;

				case 16:
					cout << "good bye, thank you to use our program." << endl;
					flag = false;
					break;
				default:
					cout << "rong selection !" << endl;
					break;
			}

			cout << "press anu key to back to main menu..";
			_getch();
			system("cls");
		}
	}
	else
	{
		cout << "connection to database faild." << endl;
	}
}

MYSQL_RES* runQuery(string query)
{
	MYSQL_RES* res;
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);

	if (!qstate)
	{
		return mysql_store_result(conn);
	}
	else
	{
		cout << "Queryt failed: " << mysql_error(conn) << endl;
		return NULL;
	}

}

void showRes(MYSQL_RES* res)
{
	MYSQL_FIELD* field;
	MYSQL_ROW row;
	int rowCount = 0;

	while (field = mysql_fetch_field(res))
	{
		cout << field->name << "\t";
		rowCount++;
	}

	cout << endl;
	cout << string(50,'-') << endl;

	while (row = mysql_fetch_row(res))
	{
		for (int i = 0; i < rowCount; i++)
		{
			cout << row[i] << "\t";
		}
		cout << endl;
	}

	cout << string(50, '-') << endl;
	cout << endl;
}

void countAlnumsBetweenTwoDates()
{
	string startDate, endDate;
	MYSQL_RES* res;

	cout << "enter start date(YYYY-MM-DD): ";
	cin >> startDate;

	cout << "enter end date(YYYY-MM-DD): ";
	cin >> endDate;

	res = runQuery("SELECT COUNT(id) FROM albums WHERE start_date >= CONVERT(\"" + startDate + "\",DATE) AND end_date <= CONVERT(\"" + endDate + "\",DATE)");
	if (res)
		cout << "the album number between " << startDate << " to " << endDate << " is " << mysql_fetch_row(res)[0] << endl;
	else
		cout << "there is no albums between " << startDate << " to " << endDate << endl;
}

void countMusicianSongsBetweenTwoDates()
{
	string musician, startDate, endDate;
	MYSQL_RES* res;

	cout << "enter musician name: ";
	cin >> musician;

	cout << "enter start date(YYYY-MM-DD): ";
	cin >> startDate;

	cout << "enter end date(YYYY-MM-DD): ";
	cin >> endDate;
	res = runQuery("SELECT COUNT(songs.id) FROM songs INNER JOIN band ON songs.id = band.song_id INNER JOIN musicians ON band.musician_id = musicians.id WHERE musicians.name = '" + musician + 
		"' AND (songs.date >= CONVERT(\"" + startDate + "\",DATE) AND songs.date <= CONVERT(\"" + endDate + "\",DATE))");
	if (res)
		cout << "the song number of musician " << musician << " is " << mysql_fetch_row(res)[0] << endl;
	else
		cout << "there is no songs for musician " << musician << " between " << startDate << " to " << endDate << endl;
}

void countMusicianAlbumsBetweenTwoDates()
{
	string musician, startDate, endDate;
	MYSQL_RES* res;

	cout << "enter musician name: ";
	cin >> musician;

	cout << "enter start date(YYYY-MM-DD): ";
	cin >> startDate;

	cout << "enter end date(YYYY-MM-DD): ";
	cin >> endDate;
	res = runQuery("SELECT songs.album_id FROM songs INNER JOIN band ON songs.id = band.song_id INNER JOIN musicians ON band.musician_id = musicians.id WHERE musicians.name = '" + musician +
		"' AND (songs.date >= CONVERT(\"" + startDate + "\",DATE) AND songs.date <= CONVERT(\"" + endDate + "\",DATE)) " + 
		"GROUP BY songs.album_id");
	if (res)
		cout << "the album number of musician " << musician << " is " << res->row_count << endl;
}

void popularInstrument()
{
	string startDate, endDate;
	MYSQL_RES* res;

	res = runQuery("SELECT musical_instruments.type AS instrument_type, COUNT(musical_instruments.type) AS instrument_count " 
					"FROM band " 
					"INNER JOIN musical_instruments ON band.instrument_id = musical_instruments.id " 
					"GROUP BY musical_instruments.type " 
					"ORDER BY instrument_count DESC");
	if (res)
		cout << "the most popular musical instrument is " <<  mysql_fetch_row(res)[0] <<endl;
}

void showAlbumInstruments()
{
	string album;
	MYSQL_RES* res;

	cout << "enter album name: ";
	cin >> album;

	res = runQuery("SELECT musical_instruments.* "
					"FROM albums "
					"INNER JOIN songs ON songs.album_id = albums.id "
					"INNER JOIN band ON songs.id = band.song_id "
					"INNER JOIN musical_instruments ON musical_instruments.id = band.instrument_id "
					"WHERE albums.name = '"+album+"'"
				);
	if (res)
		showRes(res);
}

void popularProducer()
{
	string startDate, endDate;
	MYSQL_RES* res;

	cout << "enter start date(YYYY-MM-DD): ";
	cin >> startDate;

	cout << "enter end date(YYYY-MM-DD): ";
	cin >> endDate;

	res = runQuery("SELECT producers.name AS n, COUNT(albums.id) AS c"
					"	FROM producers"
					"	INNER JOIN albums_producers ON producers.id = albums_producers.producer_id"
					"	INNER JOIN albums ON albums.id = albums_producers.album_id"
					"	WHERE albums.start_date >= CONVERT(\"" + startDate + "\",DATE) AND albums.end_date <= CONVERT(\"" + endDate + "\",DATE)"
					"	GROUP BY producers.name "
					"   ORDER BY c DESC");
	if (res)
		cout << "the most popular producer btween the selected dates is " << mysql_fetch_row(res)[0] << endl;
}

void popularInstrumentManufacturer()
{
	string startDate, endDate;
	MYSQL_RES* res;

	res = runQuery("SELECT musical_instruments.manufacturer AS n, COUNT(*) AS c "
					"	FROM musical_instruments "
					"	INNER JOIN band ON band.instrument_id = musical_instruments.id "
					"	GROUP BY musical_instruments.manufacturer "
					"   ORDER BY c DESC");
	if (res)
		cout << "the most popular musical instrument manufacturer is " << mysql_fetch_row(res)[0] << endl;
}

void musiciansNumber()
{
	string startDate, endDate;
	MYSQL_RES* res;

	res = runQuery("SELECT COUNT(DISTINCT musicians.name) "
					"FROM musicians "
					"INNER JOIN band ON musicians.id = band.musician_id "
					"INNER JOIN songs ON band.song_id = songs.id ");
	if (res)
		cout << "musecians number is " << mysql_fetch_row(res)[0] << endl;
}

void musicianPlay()
{
	string startDate, endDate;
	MYSQL_RES* res;

	res = runQuery("SELECT musicians.name as n, band.song_id AS s , "
		"SUM(((SELECT COUNT(*) FROM band WHERE band.song_id = s) - 1)) AS count_musician "
		"FROM musicians "
		"INNER JOIN band ON musicians.id = band.musician_id "
		"GROUP BY n "
		"ORDER BY count_musician DESC");

	if (res)
		cout << "the most musician famos " << mysql_fetch_row(res)[0] << endl;

}

void popularGenre()
{
	string startDate, endDate;
	MYSQL_RES* res;

	res = runQuery("SELECT songs.type, COUNT(songs.id) AS c FROM songs GROUP BY songs.type ORDER BY c DESC");

	if (res)
		cout << "popular genre is " << mysql_fetch_row(res)[0] << endl;
}

void popularTechnicianBetweenTwoDates()
{
	string musician, startDate, endDate;
	MYSQL_RES* res;

	cout << "enter start date(YYYY-MM-DD): ";
	cin >> startDate;

	cout << "enter end date(YYYY-MM-DD): ";
	cin >> endDate;

	res = runQuery("SELECT technicians.id, technicians.name, COUNT(technicians.id) AS c "
					"FROM technicians "
					"INNER JOIN songs ON songs.technician_id = technicians.id "
					"WHERE songs.date >= CONVERT(\"" + startDate + "\",DATE) "
					"AND songs.date <= CONVERT(\"" + endDate + "\",DATE) "
					"GROUP BY technicians.id, technicians.name ORDER BY c DESC");

	MYSQL_ROW row = mysql_fetch_row(res);
	if (res)
		cout << "popular Technician Between Two dates is " << row[1] << "(with id: " << row[0] << ")" << endl;
}

void firstAlbum()
{
	MYSQL_RES* res;

	res = runQuery("SELECT albums.name , MIN(albums.end_date) FROM albums");

	if (res)
		cout << "the first album was " << mysql_fetch_row(res)[0] << endl;
}

void albumHave2Songs()
{
	MYSQL_RES* res;

	res = runQuery("SELECT albums.name, albums.songs_number "
					"FROM albums "
					"INNER JOIN songs ON albums.id = songs.album_id "
					"GROUP BY albums.name, albums.songs_number "
					"HAVING COUNT(songs.id) >= 2");

	if (res)
		showRes(res);
}

void fullTechAlbum()
{
	string startDate, endDate;
	MYSQL_RES* res;

	res = runQuery("SELECT technicians.name , albums.name, albums.songs_number "
					"FROM technicians INNER JOIN songs ON songs.technician_id = technicians.id "
					"INNER JOIN albums ON songs.album_id = albums.id "
					"GROUP BY technicians.name , albums.name, albums.songs_number "
					"HAVING COUNT(songs.id) = albums.songs_number");

	if (res)
		showRes(res);
}

void mostVersatileMusician()
{
	string startDate, endDate;
	MYSQL_RES* res;

	res = runQuery("SELECT DISTINCT musicians.name, COUNT(songs.type) AS c "
					"FROM musicians "
					"INNER JOIN band ON musicians.id = band.musician_id "
					"INNER JOIN songs ON songs.id = band.song_id "
					"GROUP BY musicians.name "
					"ORDER BY c DESC");

	if (res)
		cout << "the most versatile musician is " << mysql_fetch_row(res)[0] << endl;
}
