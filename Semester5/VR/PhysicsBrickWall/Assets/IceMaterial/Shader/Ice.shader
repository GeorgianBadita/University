Shader "IndieChest/Ice"
{
	Properties
	{
		[Header(Translucency)]
		_Translucency("Strength", Range( 0 , 50)) = 1
		_TransNormalDistortion("Normal Distortion", Range( 0 , 1)) = 0.1
		_TransScattering("Scaterring Falloff", Range( 1 , 50)) = 2
		_TransDirect("Direct", Range( 0 , 1)) = 1
		_TransAmbient("Ambient", Range( 0 , 1)) = 0.2
		_TransShadow("Shadow", Range( 0 , 1)) = 0.9
		_DeepCcolor("Deep Ccolor", Color) = (1,1,1,0)
		_Surfacecolor("Surface color", Color) = (0.3396226,0.3396226,0.3396226,0)
		_MainTexture("MainTexture", 2D) = "white" {}
		[Normal]_Noise01Bump("Noise01Bump", 2D) = "white" {}
		_Icescratches("Ice scratches", 2D) = "white" {}
		_Noise1("Noise1", 2D) = "white" {}
		[HideInInspector] _texcoord( "", 2D ) = "white" {}
		[HideInInspector] __dirty( "", Int ) = 1
	}

	SubShader
	{
		Tags{ "RenderType" = "Opaque"  "Queue" = "Geometry+0" }
		Cull Back
		CGPROGRAM
		#include "UnityStandardUtils.cginc"
		#include "UnityCG.cginc"
		#include "UnityPBSLighting.cginc"
		#pragma target 3.0
		#pragma surface surf StandardCustom keepalpha addshadow fullforwardshadows exclude_path:deferred vertex:vertexDataFunc 
		struct Input
		{
			float2 uv_texcoord;
			float3 worldPos;
		};

		struct SurfaceOutputStandardCustom
		{
			half3 Albedo;
			half3 Normal;
			half3 Emission;
			half Metallic;
			half Smoothness;
			half Occlusion;
			half Alpha;
			half3 Transmission;
			half3 Translucency;
		};

		uniform sampler2D _MainTexture;
		uniform float4 _MainTexture_ST;
		uniform sampler2D _Noise01Bump;
		uniform float4 _Noise01Bump_ST;
		uniform sampler2D _Icescratches;
		uniform float4 _Icescratches_ST;
		uniform float4 _DeepCcolor;
		uniform float4 _Surfacecolor;
		uniform sampler2D _Noise1;
		uniform half _Translucency;
		uniform half _TransNormalDistortion;
		uniform half _TransScattering;
		uniform half _TransDirect;
		uniform half _TransAmbient;
		uniform half _TransShadow;

		void vertexDataFunc( inout appdata_full v, out Input o )
		{
			UNITY_INITIALIZE_OUTPUT( Input, o );
			float2 uv_MainTexture = v.texcoord * _MainTexture_ST.xy + _MainTexture_ST.zw;
			float4 tex2DNode3 = tex2Dlod( _MainTexture, float4( uv_MainTexture, 0, 0.0) );
			float3 ase_vertexNormal = v.normal.xyz;
			float2 temp_output_69_0 = frac( v.texcoord.xy );
			float2 smoothstepResult71 = smoothstep( float2( 0,0 ) , float2( 0.1,0.1 ) , temp_output_69_0);
			float2 smoothstepResult74 = smoothstep( float2( 1,1 ) , float2( 0.9,0.9 ) , temp_output_69_0);
			float2 break77 = ( smoothstepResult71 * smoothstepResult74 );
			v.vertex.xyz += ( ( ( ( tex2DNode3.g - 0.5 ) * ase_vertexNormal ) * 0.1 ) * ( break77.x * break77.y ) );
		}

		inline half4 LightingStandardCustom(SurfaceOutputStandardCustom s, half3 viewDir, UnityGI gi )
		{
			#if !DIRECTIONAL
			float3 lightAtten = gi.light.color;
			#else
			float3 lightAtten = lerp( _LightColor0.rgb, gi.light.color, _TransShadow );
			#endif
			half3 lightDir = gi.light.dir + s.Normal * _TransNormalDistortion;
			half transVdotL = pow( saturate( dot( viewDir, -lightDir ) ), _TransScattering );
			half3 translucency = lightAtten * (transVdotL * _TransDirect + gi.indirect.diffuse * _TransAmbient) * s.Translucency;
			half4 c = half4( s.Albedo * translucency * _Translucency, 0 );

			half3 transmission = max(0 , -dot(s.Normal, gi.light.dir)) * gi.light.color * s.Transmission;
			half4 d = half4(s.Albedo * transmission , 0);

			SurfaceOutputStandard r;
			r.Albedo = s.Albedo;
			r.Normal = s.Normal;
			r.Emission = s.Emission;
			r.Metallic = s.Metallic;
			r.Smoothness = s.Smoothness;
			r.Occlusion = s.Occlusion;
			r.Alpha = s.Alpha;
			return LightingStandard (r, viewDir, gi) + c + d;
		}

		inline void LightingStandardCustom_GI(SurfaceOutputStandardCustom s, UnityGIInput data, inout UnityGI gi )
		{
			#if defined(UNITY_PASS_DEFERRED) && UNITY_ENABLE_REFLECTION_BUFFERS
				gi = UnityGlobalIllumination(data, s.Occlusion, s.Normal);
			#else
				UNITY_GLOSSY_ENV_FROM_SURFACE( g, s, data );
				gi = UnityGlobalIllumination( data, s.Occlusion, s.Normal, g );
			#endif
		}

		void surf( Input i , inout SurfaceOutputStandardCustom o )
		{
			float2 uv_Noise01Bump = i.uv_texcoord * _Noise01Bump_ST.xy + _Noise01Bump_ST.zw;
			float3 tex2DNode35 = UnpackScaleNormal( tex2D( _Noise01Bump, uv_Noise01Bump ) ,0.28 );
			o.Normal = tex2DNode35;
			float2 uv_Icescratches = i.uv_texcoord * _Icescratches_ST.xy + _Icescratches_ST.zw;
			float2 uv_MainTexture = i.uv_texcoord * _MainTexture_ST.xy + _MainTexture_ST.zw;
			float4 tex2DNode3 = tex2D( _MainTexture, uv_MainTexture );
			float3 ase_worldPos = i.worldPos;
			float3 ase_worldViewDir = normalize( UnityWorldSpaceViewDir( ase_worldPos ) );
			float2 appendResult42 = (float2(ase_worldViewDir.x , ase_worldViewDir.y));
			float2 appendResult43 = (float2(tex2DNode35.r , tex2DNode35.g));
			float3 appendResult46 = (float3(( appendResult42 + appendResult43 ) , 0.0));
			float3 normalizeResult47 = normalize( appendResult46 );
			float2 paralaxOffset30 = ParallaxOffset( ( 0.5 * tex2DNode3.g ) , 1.3 , normalizeResult47 );
			float4 lerpResult54 = lerp( _DeepCcolor , _Surfacecolor , tex2D( _Noise1, ( i.uv_texcoord + paralaxOffset30 ) ).g);
			float4 temp_output_57_0 = saturate( ( tex2D( _Icescratches, uv_Icescratches ) + lerpResult54 ) );
			o.Albedo = temp_output_57_0.rgb;
			o.Smoothness = 0.9;
			o.Transmission = temp_output_57_0.rgb;
			o.Translucency = temp_output_57_0.rgb;
			o.Alpha = 1;
		}

		ENDCG
	}
	Fallback "Diffuse"
}
