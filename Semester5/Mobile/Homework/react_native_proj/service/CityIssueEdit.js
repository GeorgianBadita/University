import React, { Component } from 'react';
import { View, TextInput, Button, Text } from 'react-native';

import { getLogger, navService } from '../core';
import { CityIssueContext } from "./CityIssueContext";

const log = getLogger('CityIssueEdit');

export const CityIssueEdit = ({text = '', navigation }) => {
  const [issueDescription, setIssueDescription] = React.useState(text);
  const [solution, setSolution] = React.useState(text);
  const [severity, setSeverity] = React.useState(text);

  return (
      <CityIssueContext.Consumer>
        {({ onSubmit }) => (
            <View>
              <Text>Description: </Text>
              <TextInput
                  style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
                  onChangeText={text => setIssueDescription(text)}
                  issueDescription={issueDescription}
              />
              <Text>Solution: </Text>
              <TextInput
                  style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
              onChangeText={text => setSolution(text)}
              solution={solution}

              />

              <Text>Severity: </Text>
              <TextInput
                  style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
                  onChangeText={text => setSeverity(text)}
                  severity={severity}
              />
              <Button
                  title="Save"
                  onPress={() => {
                    log(issueDescription);
                    onSubmit({issueDescription,solution,severity})
                        .then(() => navigation.goBack())
                  }}
              />
            </View>
        )}
      </CityIssueContext.Consumer>
  );
};

CityIssueEdit.navigationOptions = () => ({
  headerTitle: 'Save City Issue',
});
