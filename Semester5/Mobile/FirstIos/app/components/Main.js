import React from 'react';
import { 
    StyleSheet, 
    Text, 
    View,
    ScrollView,
    AsyncStorage,
    Alert,
 } from 'react-native';


import Meal from './Meal';

export default class Main extends React.Component {
    constructor(props){
        super(props),
        this.state ={
            mealArray: [],
        }
    }

    /*
    componentDidMount(){
        return fetch('https://facebook.github.io/react-native/movies.json')
          .then((response) => response.json())
          .then((responseJson) => {
    
            Alert.alert(
                JSON.stringify(responseJson.movies),
                'My Alert Msg',
                [
                  {text: 'Ask me later', onPress: () => console.log('Ask me later pressed')},
                  {
                    text: 'Cancel',
                    onPress: () => console.log('Cancel Pressed'),
                    style: 'cancel',
                  },
                  {text: 'OK', onPress: () => console.log('OK Pressed')},
                ],
                {cancelable: false},
              );
 
    
          })
          .catch((error) =>{
            console.error(error);
          });
      }
    */
    render() {
        let notes = this.state.mealArray.map((val, key) => {
            return <Meal key={key} keyval={key} val={val}
            deleteMethod={() => this.deleteNote(key)}>

            </Meal>
        });
        return (
            
            <View style={styles.container}>
                <View style={styles.header}>
                    <Text style={styles.headerText}>
                        - SHARE A MEAL -
                    </Text> 
                    
                </View>
                <ScrollView style={styles.scrollContainer}>
                    {notes}
                </ScrollView>
                
            </View>
      );
    }


    componentDidMount(){
        var mealArr = this.state.mealArray;
        mealArr.push({
            'quantity':this.props.navigation.getParam('mealQuantity', ''),
            'meal': this.props.navigation.getParam('mealName', ''),
        });
        this.setState({
            mealArray: mealArr,
        })
    }

    deleteNote(key){
        this.state.mealArray.splice(key, 1);
        this.setState({
            mealArray: this.state.mealArray,
        })
        this._storeData();
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
