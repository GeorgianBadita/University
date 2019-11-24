import React from 'react';
import { 
    StyleSheet, 
    Text, 
    View,
    ScrollView,
    KeyboardAvoidingView,
    TextInput,
    TouchableOpacity,
    Alert,
 } from 'react-native';


import Meal from './Meal';
import { openDatabase } from 'react-native-sqlite-storage';
var db = openDatabase({ name: "MealsDb.db" }); 


export default class Main extends React.Component {
    constructor(props){
        super(props),
        this.state ={
            mealArray: [],
            mealName: '',
            mealQuantity: '',
        };
    }

    addMealToDb(meal){
        db.transaction(function(tx) {
            tx.executeSql(
            'INSERT INTO Meal (mealId, mealName, mealQuantity) VALUES (?,?,?)',
            [null, meal.meal, meal.quantity],
            (tx, results) => {
                console.log('Results', results.rowsAffected);
            }
            );
         });
    }

    editMealDb(oldmeal, meal){
        this.deleteMealDb(oldmeal);
        this.addMealToDb(meal);
    }

    deleteMealDb(meal){
        db.transaction(function(tx) {
            tx.executeSql(
            //'DELETE FROM Meal',
            'DELETE FROM  Meal where mealName=? and mealQuantity=?',
            [meal.meal, meal.quantity],
            (tx, results) => {
                console.log('Results', results.rowsAffected);
            }
            );
         });
    }

    componentDidMount(){
        db.transaction(tx => {
            tx.executeSql('SELECT * FROM Meal', [], (tx, results) => {
              var temp = [];
              //console.log(results.rows.length);
              for (let i = 0; i < results.rows.length; ++i) {
                tmp = results.rows.item(i);
                console.log(JSON.stringify(tmp))
                temp.push({
                    'meal' : tmp.mealName,
                    'quantity' : tmp.mealQuantity,
                });
              }
              this.setState({
                mealArray : temp,
                mealName: '',
                mealQuantity: '',
              });
            });
          });
    }

    render() {  
        let meals = this.state.mealArray.map((val, key) => {
            return <Meal key={key} keyval={key} val={val}
            deleteMethod={() => this.deleteMeal(key)} editMethod={() => this.editMeal(key)}/>
        });
        return (
            <View style={styles.container}>
                <View style={styles.header}>
                    <Text style={styles.headerText}>
                        - SHARE A MEAL -
                    </Text> 
                    
                </View>
                <ScrollView style={styles.scrollContainer}>
                    {meals}
                </ScrollView>
                
                <KeyboardAvoidingView style={styles.footer} behavior="padding" enabled>
                    <TextInput style={styles.textInput}
                    onChangeText ={(mealName) => this.setState({mealName})}
                    value={this.state.mealName}
                    placeholder='>mealName'
                    placeholderTextColor='white'
                    underlineColorAndroid='transparent'>
                    </TextInput>
                    <TextInput style={styles.textInput}
                    onChangeText ={(mealQuantity) => this.setState({mealQuantity})}
                    value={this.state.mealQuantity}
                    placeholder='>mealQauntity'
                    placeholderTextColor='white'
                    underlineColorAndroid='transparent'>
                    </TextInput>
                </KeyboardAvoidingView>
                
                <TouchableOpacity onPress={this.addMeal.bind(this)} style={styles.addButton}>
                    <Text style={styles.addButtonText}>
                        + 
                    </Text>
                </TouchableOpacity>
               

            </View>
      );
    }


    addMeal(){
        if(isNaN(this.state.mealQuantity)){
            Alert.alert('Meal quantity must be a valid number!');
        }
        if(this.state.mealName && this.state.mealQuantity && !isNaN(this.state.mealQuantity)){
            this.state.mealArray.push({
                'quantity' : this.state.mealQuantity,
                'meal': this.state.mealName,
            });
            this.addMealToDb({
                'quantity': this.state.mealQuantity,
                'meal' : this.state.mealName,
            })
            this.setState({
               mealArray : this.state.mealArray,
               mealName: '',
               mealQuantity: '',
            })
        }
    }

    editMeal(key){
        console.log("Pressed " + key);
        var meal = this.state.mealArray[key];
        if(this.state.mealName && this.state.mealQuantity){
            this.state.mealArray.splice(key, 1);
            this.state.mealArray.push({
                'meal': this.state.mealName,
                'quantity': this.state.mealQuantity,
            })
            this.setState({
                mealArray: this.state.mealArray,
                mealName: '',
                mealQuantity: '',
            })
            this.editMealDb(meal, {
                'meal' : this.state.mealName,
                'quantity' : this.state.mealQuantity,
            })
        }
        if(this.state.mealName && !this.state.mealQuantity){
            this.state.mealArray[key] = {'quantity': meal.quantity, 'meal': this.state.mealName}
            this.editMealDb(meal, {
                'meal' : this.state.mealName,
                'quantity' : meal.quantity,
            })
            this.setState({
                mealArray: this.state.mealArray,
                mealName: '',
            })
        }

        if(isNaN(this.state.mealQuantity)){
            Alert.alert('Meal quantity must be a valid number!');
            return;
        }
        if(!this.state.mealName && this.state.mealQuantity){
            this.state.mealArray[key] = {'quantity' : this.state.mealQuantity, 'meal':meal.meal}
            this.editMealDb(meal, {
                'meal' : meal.meal,
                'quantity' :this.state.mealQuantity,
            })
            this.setState({
                mealArray: this.state.mealArray,
                mealQuantity: '',
            })
        }
    }

    deleteMeal(key){
        console.log(this.state.mealArray[key]);
        this.deleteMealDb(this.state.mealArray[key]);
        this.state.mealArray.splice(key, 1);
        this.setState({
            mealArray: this.state.mealArray,
        })
    }
}

const styles = StyleSheet.create({
    container: {
        flex: 1,
    },

    header: {
        backgroundColor: '#DBD5F1',
        alignItems: 'center',
        justifyContent: 'center',
        borderBottomWidth: 10,
        borderBottomColor: '#ddd',
    },

    headerText: {
        color: 'white',
        fontSize: 18,
        padding: 26,
    },

    scrollContainer: {
        flex: 1,
        marginBottom: 100,
    },

    footer: {
        position: 'absolute',
        bottom: 0,
        left: 0,
        right: 0,
        zIndex: 10,

    },

    textInput: {
        alignSelf: 'stretch',
        color: '#fff',
        padding: 20,
        backgroundColor: '#252525',
        borderTopWidth: 2,
        borderTopColor: '#ededed',
    },

    addButton: {
        position: 'absolute',
        zIndex: 11,
        right: 20,
        bottom: 90,
        backgroundColor: '#DBD5F1',
        width: 90,
        height: 90,
        borderRadius: 50,
        alignItems: 'center',
        justifyContent: 'center',
        elevation: 8,
    },

    addButtonText: {
        color: '#fff',
        fontSize: 24,
    },
});
