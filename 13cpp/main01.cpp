/* Standard C++ includes */
//#pragma comment(lib, "mysqlcppconn-static")
#include <stdlib.h>
#include <iostream>

#define CPPCONN_LIB_BUILD

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std;

int main(void)
{
cout << endl;
//cout << "Running 'SELECT 'Hello World!' AS _message'..." << endl;

try {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  /* Create a connection */
  driver = get_driver_instance();
  con = driver->connect("tcp://127.0.0.1:3306", "root", "mysql");
  /* Connect to the MySQL test database */
  //con->setSchema("test");

  stmt = con->createStatement();

  stmt->execute("use test");

  res = stmt->executeQuery("SELECT * FROM `contacts`");

  cout << res->isBeforeFirst() << endl;
  cout << res->isAfterLast() << endl;

  cout << res->getRow() << endl;

  while (res->next())
  {
	  double money = 0;
	  int age = 0;
	  string name, address, phone;
	  name = res->getString("name");
	  age = res->getInt("age");
	  phone = res->getString("phone");
	  address = res->getString("address");
	  money = res->getDouble("money");

	  cout << name << " " << age << " " << phone << " " << address << " " << money << endl;
  }


  // try to check the table is exist.
  //cout << stmt->execute("SHOW TABLES LIKE '%wang%'");

  //int cnt = stmt->executeUpdate("delete from zhang where `name` = \"zhang\"");
  //cout << cnt;
  //return 0;
  //while (res->next()) {
  //  cout << "\t... MySQL replies: ";
  //  /* Access column data by alias or column name */
  //  cout << res->getString("_message") << endl;
  //  cout << "\t... MySQL says it again: ";
  //  /* Access column fata by numeric offset, 1 is the first column */
  //  cout << res->getString(1) << endl;
  //}
  //delete res;
  delete stmt;
  delete con;

} catch (sql::SQLException &e) {
  cout << "# ERR: SQLException in " << __FILE__;
  cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
  cout << "# ERR: " << e.what();
  cout << " (MySQL error code: " << e.getErrorCode();
  cout << ", SQLState: " << e.getSQLState() << " )" << endl;
}

cout << endl;

return EXIT_SUCCESS;
}