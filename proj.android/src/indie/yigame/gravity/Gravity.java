/****************************************************************************
Copyright (c) 2010-2011 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package indie.yigame.gravity;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;
import org.json.JSONException;
import org.json.JSONObject;

import com.easyndk.classes.AndroidNDKHelper;
import com.tendcloud.tenddata.TalkingDataGA;

import android.app.AlertDialog;
import android.os.Bundle;
import android.util.Log;

public class Gravity extends Cocos2dxActivity{
	
    protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);	
		TalkingDataGA.init(getContext(), "703B278DD40E7AFA2114205E161F51FD", "app_meizu");
	}

    public Cocos2dxGLSurfaceView onCreateView() {
    	Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
    	// Gravity should create stencil buffer
    	glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
    	AndroidNDKHelper.SetNDKReciever(this);
    	return glSurfaceView;
    }
    
    @Override
    protected void onResume() {
        super.onResume();
        Log.d("TalkingDataCocos2dx", "onResume");
        TalkingDataGA.onResume(this);
    }
    
    @Override
    protected void onPause() {
        super.onPause();
        Log.d("TalkingDataCocos2dx", "onPause");
        TalkingDataGA.onPause(this);
    }
    
    public void SampleSelectorWithData(JSONObject prms)
    {
    	Log.v("SampleSelector", "purchase something called");
    	Log.v("SampleSelector", "Passed params are : " + prms.toString());
    	
    	String CPPFunctionToBeCalled = null;
		try
		{
			CPPFunctionToBeCalled = prms.getString("to_be_called");
		}
		catch (JSONException e)
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	
    	AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setMessage("This is a sample popup on Android").
        setTitle("Hello World!").
        setNeutralButton("OK", null).show();
        
        String jsonStr = "{\"sample_dictionary\":{\"sample_array\":[\"1\",\"2\",\"3\",\"4\",\"5\",\"6\",\"7\",\"8\",\"9\",\"10\",\"11\"],\"sample_integer\":1234,\"sample_float\":12.34,\"sample_string\":\"a string\"}}";
        JSONObject prmsToSend = null;
        
        try
        {
			prmsToSend = new JSONObject(jsonStr);
		}
        catch (JSONException e)
        {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        
        if (prmsToSend != null)
        {
        	AndroidNDKHelper.SendMessageWithParameters(CPPFunctionToBeCalled, prmsToSend);
        }
        else
        {
        	AndroidNDKHelper.SendMessageWithParameters(CPPFunctionToBeCalled, null);
        }
    }
    
    static {
        System.loadLibrary("cocos2dcpp");
    }     
}
