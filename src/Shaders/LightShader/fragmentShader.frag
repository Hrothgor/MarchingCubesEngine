#version 430 core

in vec2 pass_textureCoords;
in vec3 surfaceNormal;
in vec3 toLightVector;
in vec3 toCameraVector;

out vec4 out_Pixel;

uniform sampler2D textureSampler;
uniform vec3 lightColor;
uniform float shineDamper;
uniform float reflectivity;
uniform vec3 ambientColor;

void main(void)
{
    vec3 unitSurfaceNormal = normalize(surfaceNormal);
    vec3 unitToLightVector = normalize(toLightVector);

    float NormalLightDot = dot(unitSurfaceNormal, unitToLightVector);
    float brightness = max(NormalLightDot, 0.2);
    vec3 diffuseColor = brightness * lightColor;

    vec3 unitToCameraVector = normalize(toCameraVector);
    vec3 lightDirection = -unitToLightVector;
    vec3 reflectedLightDirection = reflect(lightDirection, unitSurfaceNormal);

    float specularFactor = dot(reflectedLightDirection, unitToCameraVector);
    specularFactor = max(specularFactor, 0.0);
    vec3 finalSpecular = pow(specularFactor, shineDamper) * reflectivity * lightColor;

    // out_Pixel = vec4(diffuseColor, 1.0) * vec4(ambientColor, 1.0) * texture(textureSampler, pass_textureCoords) + vec4(finalSpecular, 1.0);
    out_Pixel = vec4(diffuseColor, 1.0) * texture(textureSampler, pass_textureCoords) + vec4(finalSpecular, 1.0);
}
