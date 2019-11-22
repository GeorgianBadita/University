import React, { Component } from 'react';
import { ActivityIndicator, Button, StyleSheet, Text, TextInput, View } from 'react-native';

import { getLogger } from '../core';
import { Consumer } from './AuthContext';

const log = getLogger('SignIn');

export const SignIn = ({ navigation }) => {
  log('render');
  const [ username, onChangeUsername ] = React.useState('');
  const [ password, onChangePassword ] = React.useState('');
  return (
    <Consumer>
      {({ onSignIn, signInError, signInInProgress }) => (
        <View>
          <ActivityIndicator animating={signInInProgress} size="large"/>
          {signInError && <Text>{signInError.message || 'Sign in error'}</Text>}
          <TextInput
            style={styles.textInput}
            placeholder="Username"
            onChangeText={text => onChangeUsername(text)}
            value={username}
          />
          <TextInput
            style={styles.textInput}
            placeholder="Password"
            onChangeText={text => onChangePassword(text)}
            secureTextEntry={true}
            value={password}
          />
          <Button title="Sign in!" onPress={() => {
            onSignIn(username, password)
              .then(() => navigation.navigate('Todo'))
          }} />
        </View>
      )}
    </Consumer>
  );
};

SignIn.navigationOptions = () => ({
  headerTitle: 'Please Sign In',
});

const styles = StyleSheet.create({
  textInput: {
    height: 40,
    borderColor: 'gray',
    borderWidth: 1,
  }
});