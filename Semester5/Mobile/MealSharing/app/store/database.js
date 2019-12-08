import SQLite from "react-native-sqlite-storage";

SQLite.DEBUG(true);
SQLite.enablePromise(true);

const database_name = "MealsDb.db";
const database_version = "1.0";
const database_displayname = "SQLite React Share a Meal Database";
const database_size = 20000000;

export default class Database{
    initDB(){
        let db;
        return new Promise((resolve) => {
          console.log("Plugin integrity check ...");
          SQLite.echoTest()
            .then(() => {
              console.log("Integrity check passed ...");
              console.log("Opening database ...");
              SQLite.openDatabase(
                database_name,
                database_version,
                database_displayname,
                database_size
              )
                .then(DB => {
                  db = DB;
                  console.log("Database OPEN");
                  db.executeSql('SELECT 1 FROM Meal LIMIT 1').then(() => {
                      console.log("Database is ready ... executing query ...");
                  }).catch((error) =>{
                      console.log("Received error: ", error);
                      console.log("Database not yet ready ... populating data");
                      db.transaction((tx) => {
                          tx.executeSql('CREATE TABLE IF NOT EXISTS Meal (mealId, mealName, mealQuantity)');
                      }).then(() => {
                          console.log("Table created successfully");
                      }).catch(error => {
                          console.log(error);
                      });
                  });
                  resolve(db);
                })
                .catch(error => {
                  console.log(error);
                });
            })
            .catch(error => {
              console.log("echoTest failed - plugin not functional");
            });
          });
    }

    closeDatabase(db) {
        if (db) {
          console.log("Closing DB");
          db.close()
            .then(status => {
              console.log("Database CLOSED");
            })
            .catch(error => {
              this.errorCB(error);
            });
        } else {
          console.log("Database was not OPENED");
        }
      };


      

      listMeal() {
        let db = this.initDB();
        console.log(db)
        db.transaction(tx => {
          tx.executeSql('SELECT * FROM Meal', [], (tx, results) => {
            var temp = [];
            for (let i = 0; i < results.rows.length; ++i) {
              temp.push(results.rows.item(i));
            }
            return temp;
          });
        });
      }
      
      
    addMeal(meal) {
      return new Promise((resolve) => {
        this.initDB().then((db) => {
          db.transaction((tx) => {
            tx.executeSql('INSERT INTO Meal VALUES (?,?, ?)', [null, meal.meal, meal.quantity]).then(([tx, results]) => {
              resolve(results);
            });
          }).then((result) => {
            this.closeDatabase(db);
          }).catch((err) => {
            console.log(err);
          });
        }).catch((err) => {
          console.log(err);
        });
      });  
    }

}