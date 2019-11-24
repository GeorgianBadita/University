import React from 'react';
import { 
    StyleSheet, 
    Text, 
    View,
    TouchableOpacity,
 } from 'react-native';

export default class Meal extends React.Component {
  render() {
      return (
          <View key={this.props.keyval} style={styles.note}>
            <Text style={styles.noteText}>{"Meal: " + this.props.val.meal} </Text>
            <Text style={styles.noteText}>{"Quantity:"  + this.props.val.quantity}</Text>
        
            <TouchableOpacity onPress={this.props.editMethod} style={styles.noteEdit}>
                <Text style={styles.noteDeleteText}>Edit</Text>
            </TouchableOpacity>
            <TouchableOpacity onPress={this.props.deleteMethod} style={styles.noteDelete}>
                <Text style={styles.noteDeleteText}>Del</Text>
            </TouchableOpacity>
          </View>
      );
    }

}

const styles = StyleSheet.create({
    note: {
        position: 'relative',
        padding: 20,
        paddingRight:100,
        borderBottomWidth: 2,
        borderBottomColor: '#ededed',
    },
    noteText: {
        paddingLeft: 20,
        borderLeftWidth: 10,
        borderLeftColor: '#e91e63',
    },
    noteDelete: {
        position: 'absolute',
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: '#2980b9',
        padding: 10,
        top: 10,
        bottom: 10,
        right: 10
    },
    noteEdit:{
        position: 'absolute',
        justifyContent: 'center',
        alignItems: 'center',
        backgroundColor: '#000000',
        padding: 10,
        top: 10,
        bottom: 10,
        right: 70
    },
    noteDeleteText: {
        color: 'white',
    }
});
