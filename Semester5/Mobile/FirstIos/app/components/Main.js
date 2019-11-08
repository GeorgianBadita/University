import React from 'react';
import { 
    StyleSheet, 
    Text, 
    View,
    TextInput,
    ScrollView,
    TouchableOpacity,
    KeyboardAvoidingView,
    Alert,
 } from 'react-native';


import Note from './Note';

export default class Main extends React.Component {
    constructor(props){
        super(props),
        this.state ={
            noteArray: [],
            noteText: '',
        }
    }

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

    render() {
        
        let notes = this.state.noteArray.map((val, key) => {
            return <Note key={key} keyval={key} val={val}
            deleteMethod={() => this.deleteNote(key)}>

            </Note>
        });
        
        
        return (
            <View style={styles.container}>
                <View style={styles.header}>
                    <Text style={styles.headerText}>
                        - NOTER -
                    </Text>
                </View>
                <ScrollView style={styles.scrollContainer}>
                    {notes}
                </ScrollView>

                <KeyboardAvoidingView style={styles.footer} behavior="padding" enabled>
                    <TextInput style={styles.textInput}
                    onChangeText ={(noteText) => this.setState({noteText})}
                    value={this.state.noteText}
                    placeholder='>note'
                    placeholderTextColor='white'
                    underlineColorAndroid='transparent'>
                    </TextInput>
                </KeyboardAvoidingView>

                <TouchableOpacity onPress={this.addNote.bind(this)} style={styles.addButton}>
                    <Text style={styles.addButtonText}>
                        + 
                    </Text>
                </TouchableOpacity>

            </View>
      );
    }

deleteNote(key){
    this.state.noteArray.splice(key, 1);
    this.setState({
        noteArray: this.state.noteArray,
        noteText: ''
    })
}

addNote(){
    if(this.state.noteText){
        var d = new Date();
        this.state.noteArray.push({
            'date': d.getFullYear() + '/' + (d.getMonth() + 1) + '/' + d.getDay(),
            'note': this.state.noteText,
        });
        this.setState({
           noteArray : this.state.noteArray,
           noteText: '',
        })
    }
}

}

const styles = StyleSheet.create({
    container: {
        flex: 1,
    },

    header: {
        backgroundColor: '#e91e63',
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
        backgroundColor: '#e91e63',
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
