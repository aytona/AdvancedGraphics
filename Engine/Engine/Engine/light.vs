// GLOBALS
cbuffer MatrixBuffer
{
	matrix worldMatrix;
	matrix viewMatrix;
	matrix projectionMatrix;
};

// TYPEDEFS
struct VertexInputType
{
	float4 position : POSITION;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

struct PixelInputType
{
	float4 position : SV_POSITION;
	float2 tex : TEXCOORD0;
	float3 normal : NORMAL;
};

// Vertex Shader
PixelInputType LightVertexShader(VertexInputType input)
{
	PixelInputType output;

    // Change vector to be 4 units for proper matrix calculations
	input.position.w = 1.0f;

    // Calculate position of vertex
    output.position = mul(input.position, worldMatrix);
	output.position = mul(output.position, viewMatrix);
	output.position = mul(output.position, projectionMatrix);

    // Store texture coord for pixel shader
	output.tex = input.tex;

	output.normal = mul(input.position, (float3x3)worldMatrix);

	output.normal = normalize(output.normal);

	return output;
}