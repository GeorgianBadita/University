import React from 'react';
import { 
    StyleSheet, 
    View,
    TextInput,
    Button,
 } from 'react-native';




export default class AddMeal extends React.Component {
    constructor(props){
        super(props)
        this.state={
            mealName: '',
            mealQuantity: '',
        }
    }

  
    render() {
        return (
            <View style={styles.container}>
                    <TextInput style={styles.textInput}
                    placeholder='Meal'
                    onChangeText = {(mealName) => this.setState({mealName})}
                    placeholderTextColor='white'
                    underlineColorAndroid='transparent'>
                    </TextInput>

                    <TextInput style={styles.textInput}
                    placeholder='Quantity'
                    onChangeText = {(mealQuantity) => this.setState({mealQuantity})}
                    placeholderTextColor='white'
                    underlineColorAndroid='transparent'>
                    </TextInput>

                    <Button
                        title = "Add Meal"
                        color = "#DBD5F1"
                        onPress = {() => this.props.navigation.navigate('MainScreen',
                        {
                            mealName: this.state.mealName,
                            mealQuantity: this.state.mealQuantity,
                        })}
                    />
            </View>
      );
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
