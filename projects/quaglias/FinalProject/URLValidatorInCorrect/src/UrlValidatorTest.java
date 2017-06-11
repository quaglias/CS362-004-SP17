/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;
import java.util.Random;




/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   
	   //Will probably need to combine both sections to make it easier to read at runtime
	   System.out.println("Manual Test Results for isValid():");
	   System.out.println("1) http://www.amazon.com: " + urlVal.isValid("http://www.amazon.com"));
	   System.out.println("2) http:////www.google.com: " +urlVal.isValid("http:////www.google.com"));
	   System.out.println("3) http://www. .com: " + urlVal.isValid("http://www. .com"));
	   System.out.println("4) http:////www..com: " + urlVal.isValid("http:////www..com"));
	   System.out.println("5) http://www.__.com: " + urlVal.isValid("http://www.__.com"));
	   System.out.println("5) http:////www.g g.com: " + urlVal.isValid("http:////www.g g.com"));
	   System.out.println("6) http://www.amazon.org: " + urlVal.isValid("http://www.amazon.org"));
	   System.out.println("7) http://www.google.cm: " + urlVal.isValid("http://www.google.cm"));
	   System.out.println("8) http://www.amazon.com.uy: " + urlVal.isValid("http://www.amazon.com.uy"));
	   System.out.println("9) http://www.google.us: " + urlVal.isValid("http://www.google.us"));
	   
	   System.out.println("Expected Manual Test Results:");
	   System.out.println("1) http://www.amazon.com: True");
	   System.out.println("2) http:////www.google.com: False");
	   System.out.println("3) http://www. .com: False");
	   System.out.println("4) http:////www..com: False");
	   System.out.println("5) http://www.__.com: False");
	   System.out.println("5) http:////www.g g.com: False");
	   System.out.println("6) http://www.amazon.org: True");
	   System.out.println("7) http://www.google.cm: False");
	   System.out.println("8) http://www.amazon.com.uy: True");
	   System.out.println("9) http://www.google.us: True");
	   
	   
	   
	   
   }
   
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator();
     
	   String validSchemeArray[] = new String[5];
       validSchemeArray[0] = "http://";
       validSchemeArray[1] = "";
       validSchemeArray[2] = "a2pp://";   //invalid value
       validSchemeArray[3] = "";		//invalid value
       validSchemeArray[4] = " //";		//invalid value
       
       
       String validAuthorityArray[] = new String[3];
       validAuthorityArray[0] = "www.amazon.com";
       validAuthorityArray[1] = "google.com";
       validAuthorityArray[2] = "125.5.8.107";
       
       String validPortArray[] = new String[2];
       validPortArray[0] = ":80";
       validPortArray[1] = "";
       
       String validPathArray[] = new String[2];
       validPathArray[0] = "/index";
       validPathArray[1] = "";
       
       String validQueryArray[] = new String[2];
       validQueryArray[0] = "?q=URL";
       validQueryArray[1] = "";
       
       String testString;
       
       int i = 0;
       int j = 0;
       int k = 0;
       int l = 0;
       int m = 0;
       
       System.out.println("Partition Test Results for isValid():");
       for(i = 0; i < validSchemeArray.length; i++)
       {
           for(j = 0; j < validAuthorityArray.length; j++)
           {
               for(k = 0; k < validPortArray.length; k++)
               {
                   for(l = 0; l < validPathArray.length; l++)
                   {
                       for(m = 0; m < validQueryArray.length; m++)
                       {
                           testString = validSchemeArray[i] + validAuthorityArray[j] + validPortArray[k] + validPathArray[l] + validQueryArray[m];
                           System.out.println("Testing: " + testString);
                           System.out.println("Result: " + urlVal.isValid(testString));
                           testString = "";
                               
                       }
                   }
                       
               }
           }
       }

   }
   
   public void testYourSecondPartition()
   {
	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);   
	String validSchemeArray[] = new String[2];
       validSchemeArray[0] = "http://";
       validSchemeArray[1] = "";

       String validAuthorityArray[] = new String[5];
       validAuthorityArray[0] = "www.amazon.com";
       validAuthorityArray[1] = "google.com";
       validAuthorityArray[2] = "125.5.8.107";
       validAuthorityArray[3] = " ";					//invalid value
       validAuthorityArray[4] = "361.569.291.357";		//invalid value
       
       String validPortArray[] = new String[2];
       validPortArray[0] = ":80";
       validPortArray[1] = "";
       
       String validPathArray[] = new String[2];
       validPathArray[0] = "/index";
       validPathArray[1] = "";
       
       String validQueryArray[] = new String[2];
       validQueryArray[0] = "?q=URL";
       validQueryArray[1] = "";

       String testString;
       
       int i = 0;
       int j = 0;
       int k = 0;
       int l = 0;
       int m = 0;
       
       System.out.println("Partition Test Results for isValid():");
       for(i = 0; i < validSchemeArray.length; i++)
       {
           for(j = 0; j < validAuthorityArray.length; j++)
           {
               for(k = 0; k < validPortArray.length; k++)
               {
                   for(l = 0; l < validPathArray.length; l++)
                   {
                       for(m = 0; m < validQueryArray.length; m++)
                       {
                           testString = validSchemeArray[i] + validAuthorityArray[j] + validPortArray[k] + validPathArray[l] + validQueryArray[m];
                           System.out.println("Testing: " + testString);
                           System.out.println("Result: " + urlVal.isValid(testString));
                           testString = "";
                               
                       }
                   }
                       
               }
           }
       }
   }
   
   public void testYourThirdPartition()
   {
	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);   
	String validSchemeArray[] = new String[2];
       validSchemeArray[0] = "http://";
       validSchemeArray[1] = "";

       String validAuthorityArray[] = new String[3];
       validAuthorityArray[0] = "www.amazon.com";
       validAuthorityArray[1] = "google.com";
       validAuthorityArray[2] = "125.5.8.107";
       
       String validPortArray[] = new String[4];
       validPortArray[0] = ":80";
       validPortArray[1] = "";
       validPortArray[2] = "::";     //invalid value     
       validPortArray[3] = ":\00";   //invalid value
       
       String validPathArray[] = new String[2];
       validPathArray[0] = "/index";
       validPathArray[1] = "";
       
       String validQueryArray[] = new String[2];
       validQueryArray[0] = "?q=URL";
       validQueryArray[1] = "";

       String testString;
       
       int i = 0;
       int j = 0;
       int k = 0;
       int l = 0;
       int m = 0;
       
       System.out.println("Partition Test Results for isValid():");
       for(i = 0; i < validSchemeArray.length; i++)
       {
           for(j = 0; j < validAuthorityArray.length; j++)
           {
               for(k = 0; k < validPortArray.length; k++)
               {
                   for(l = 0; l < validPathArray.length; l++)
                   {
                       for(m = 0; m < validQueryArray.length; m++)
                       {
                           testString = validSchemeArray[i] + validAuthorityArray[j] + validPortArray[k] + validPathArray[l] + validQueryArray[m];
                           System.out.println("Testing: " + testString);
                           System.out.println("Result: " + urlVal.isValid(testString));
                           testString = "";
                               
                       }
                   }
                       
               }
           }
       }
   } 
 
   public void testYourFourthPartition()
   {
	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);   
	String validSchemeArray[] = new String[2];
       validSchemeArray[0] = "http://";
       validSchemeArray[1] = "";

       String validAuthorityArray[] = new String[3];
       validAuthorityArray[0] = "www.amazon.com";
       validAuthorityArray[1] = "google.com";
       validAuthorityArray[2] = "125.5.8.107";
       
       String validPortArray[] = new String[2];
       validPortArray[0] = ":80";
       validPortArray[1] = "";
       
       String validPathArray[] = new String[4];
       validPathArray[0] = "/index";
       validPathArray[1] = "";
       validPathArray[1] = "/::-1";	//invalid value
       validPathArray[1] = ":9099"; //invalid value
       
       String validQueryArray[] = new String[2];
       validQueryArray[0] = "?q=URL";
       validQueryArray[1] = "";

       String testString;
       
       int i = 0;
       int j = 0;
       int k = 0;
       int l = 0;
       int m = 0;
       
       System.out.println("Partition Test Results for isValid():");
       for(i = 0; i < validSchemeArray.length; i++)
       {
           for(j = 0; j < validAuthorityArray.length; j++)
           {
               for(k = 0; k < validPortArray.length; k++)
               {
                   for(l = 0; l < validPathArray.length; l++)
                   {
                       for(m = 0; m < validQueryArray.length; m++)
                       {
                           testString = validSchemeArray[i] + validAuthorityArray[j] + validPortArray[k] + validPathArray[l] + validQueryArray[m];
                           System.out.println("Testing: " + testString);
                           System.out.println("Result: " + urlVal.isValid(testString));
                           testString = "";
                               
                       }
                   }
                       
               }
           }
       }
   } 
   
   
   
   public void testYourFifthPartition()
   {
	UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);   
	String validSchemeArray[] = new String[2];
       validSchemeArray[0] = "http://";
       validSchemeArray[1] = "";

       String validAuthorityArray[] = new String[3];
       validAuthorityArray[0] = "www.amazon.com";
       validAuthorityArray[1] = "google.com";
       validAuthorityArray[2] = "125.5.8.107";
       
       String validPortArray[] = new String[2];
       validPortArray[0] = ":80";
       validPortArray[1] = "";
       
       String validPathArray[] = new String[2];
       validPathArray[0] = "/index";
       validPathArray[1] = "";
       
       String validQueryArray[] = new String[4];
       validQueryArray[0] = "?q=URL";
       validQueryArray[1] = "";
       validQueryArray[2] = ":://";		//invalid value
       validQueryArray[3] = "?=??*9";	//invalid value

       String testString;
       
       int i = 0;
       int j = 0;
       int k = 0;
       int l = 0;
       int m = 0;
       
       System.out.println("Partition Test Results for isValid():");
       for(i = 0; i < validSchemeArray.length; i++)
       {
           for(j = 0; j < validAuthorityArray.length; j++)
           {
               for(k = 0; k < validPortArray.length; k++)
               {
                   for(l = 0; l < validPathArray.length; l++)
                   {
                       for(m = 0; m < validQueryArray.length; m++)
                       {
                           testString = validSchemeArray[i] + validAuthorityArray[j] + validPortArray[k] + validPathArray[l] + validQueryArray[m];
                           System.out.println("Testing: " + testString);
                           System.out.println("Result: " + urlVal.isValid(testString));
                           testString = "";
                               
                       }
                   }
                       
               }
           }
       }
   } 
   
   	String[] urlSchemes = {"http://", "http:", "https:", "batman", "://", ""};
   	String[] urlAuthority = {"www.google.com", "go.au", "255.255.255.255", "1.2.3", ""};
   	String[] urlPort = {":80", ":65535", ";0", ":-1", "65a"};
   	String[] urlPath = {"/test1", "/..", ""};
   	String[] urlQueries = {"?action=view", "?action=edit&mode=up", ""};
   	 
   	 
   	public void testIsValid()
   	{

   		System.out.println("\n testIsValidScheme() ");

        Random rand = new Random();
   	       
   	   for(int i = 0;i<100;i++)
   	   {
   		   int Scheme = rand.nextInt(urlSchemes.length) + 0;
   	       int Authority = rand.nextInt(urlAuthority.length) + 0;
   	       int Path = rand.nextInt(urlPath.length) + 0;
   	       String url = this.urlSchemes[Scheme] + this.urlAuthority[Authority] + this.urlPath[Path];
   	       System.out.println(url);
   	       UrlValidator urlVal = new UrlValidator();
   	       boolean result = urlVal.isValid(url);

   	       if (result == true) 
   	       {
   	    	   System.out.println("Passed");
   	       }
   	       else 
   	       {
   	    	   System.out.println("Failed");
   	       }
   	   }
   	          
   	System.out.println();

   }  

   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
