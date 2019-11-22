using System;
using UnityEngine;

public class RandomMovement : MonoBehaviour
{
    GameObject robot;
    GameObject head, body, rUpperArm, rLowerArm, lUpperArm, lLowerArm, lUpperLeg, lLowerLeg, rUpperLeg, rLowerLeg;
    GameObject lElbow, lShoulder;
    GameObject rElbow, rShoulder;
    GameObject lButt, lKnee;
    GameObject rButt, rKnee;
    bool limbAnimationForward;
    public float movementSpeed { get; set; }

    public float rotationSpeed { get { return movementSpeed * 30; } }

    // Start is called before the first frame update
    void Start()
    {
        robot = GameObject.Find("AnimatedRobot");
        head = GameObject.Find("head");
        body = GameObject.Find("body");
        rUpperArm = GameObject.Find("rUpperArm");
        rLowerArm = GameObject.Find("rLowerArm");
        lUpperArm = GameObject.Find("lUpperArm");
        lLowerArm = GameObject.Find("lLowerArm");
        lUpperLeg = GameObject.Find("lUpperLeg");
        lLowerLeg = GameObject.Find("lLowerLeg");
        rUpperLeg = GameObject.Find("rUpperLeg");
        rLowerLeg = GameObject.Find("rLowerLeg");
        lElbow = GameObject.Find("lElbow");
        lShoulder = GameObject.Find("lShoulder");
        rElbow = GameObject.Find("rElbow");
        rShoulder = GameObject.Find("rShoulder");
        lButt = GameObject.Find("lButt");
        lKnee = GameObject.Find("lKnee");
        rButt = GameObject.Find("rButt");
        rKnee = GameObject.Find("rKnee");
        movementSpeed = 5;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.W))
        {
            MoveForward();
        }
        if (Input.GetKey(KeyCode.S))
        {
            MoveBackward();
        }

    }

    /// <summary>
    /// Animates the limbs of the robot.
    /// </summary>
    void AnimateLimbs()
    {
        
        
        if (lUpperLeg.transform.rotation.x > 0)
        {
            
            if (!limbAnimationForward)
            {
                lLowerLeg.transform.RotateAround(lKnee.transform.position, Vector3.left, 
                    rotationSpeed * 3 * Time.deltaTime);
                //lLowerArm.transform.RotateAround(lElbow.transform.position, Vector3.right, rotationSpeed * 3 * Time.deltaTime);
            }
            else
            {
                lLowerLeg.transform.RotateAround(lKnee.transform.position, Vector3.right, 
                    rotationSpeed * 2.7811f * Time.deltaTime);
                //lLowerArm.transform.RotateAround(lElbow.transform.position, Vector3.left, rotationSpeed * 2.7813f * Time.deltaTime);
            }
        }

        
        if (rUpperLeg.transform.rotation.x > 0)
        {
            if (limbAnimationForward)
            {
                rLowerLeg.transform.RotateAround(rKnee.transform.position, Vector3.left,
                    rotationSpeed * 3 * Time.deltaTime);
            }
            else
            {
                rLowerLeg.transform.RotateAround(rKnee.transform.position, Vector3.right,
                    rotationSpeed * 2.7811f * Time.deltaTime);
            }
        }
        Debug.Log(lUpperArm.transform.rotation);
        if (Math.Abs(lUpperArm.transform.rotation.x) > 0.25f)
        {
            limbAnimationForward = !limbAnimationForward;
        }
        
        
        if (limbAnimationForward)
        {
            lUpperArm.transform.RotateAround(lShoulder.transform.position, Vector3.left, rotationSpeed * Time.deltaTime);
            rUpperArm.transform.RotateAround(rShoulder.transform.position, Vector3.right, rotationSpeed * Time.deltaTime);

            lUpperLeg.transform.RotateAround(lButt.transform.position, Vector3.right, rotationSpeed * Time.deltaTime);
            rUpperLeg.transform.RotateAround(rButt.transform.position, Vector3.left, rotationSpeed * Time.deltaTime);
        }
        else
        {
            lUpperArm.transform.RotateAround(lShoulder.transform.position, Vector3.right, rotationSpeed * Time.deltaTime);
            rUpperArm.transform.RotateAround(rShoulder.transform.position, Vector3.left, rotationSpeed * Time.deltaTime);

            lUpperLeg.transform.RotateAround(lButt.transform.position, Vector3.left, rotationSpeed * Time.deltaTime);
            rUpperLeg.transform.RotateAround(rButt.transform.position, Vector3.right, rotationSpeed * Time.deltaTime);
        }
        
    }

    void MoveForward()
    {
        robot.transform.Translate(translation: movementSpeed * Time.deltaTime * Vector3.forward);
        AnimateLimbs();
    }

    void MoveBackward()
    {
        robot.transform.Translate(movementSpeed * Time.deltaTime * Vector3.back);
        AnimateLimbs();
    }

}
