import groovy.json.JsonSlurper
pipeline{  
  agent any
  stages{
      stage('Build C Project')
      {
        steps
        {         
          sh "make"          
        }
      }
      stage('Sonarqube Analysis'){
        environment {
           scannerHome = tool 'SonarQube Runner'
        }
        steps {
          withSonarQubeEnv('SonarQube Scanner') {
             sh 'sudo sonar:sonar'               
          }
        }
      }
      
         
  }
 }
